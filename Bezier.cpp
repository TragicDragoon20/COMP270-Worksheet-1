#include "stdafx.h"
#include "Bezier.h"
#include "math.h"

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
	: p0(p0), p1(p1), p2(p2), p3(p3)
{
}

void Bezier::draw(SDL_Renderer *renderer) const
{
	const int numOfLineSegments = 20;
	
	Vector2 bezierPoints[numOfLineSegments];

	for (float i = 0; i < numOfLineSegments; i++)
	{

		Vector2 pos[] =
		{
			bezierCurve(i / numOfLineSegments),
			bezierCurve((i + 1) / numOfLineSegments)
		};

		SDL_RenderDrawLineF(renderer, pos[0].x, pos[0].y, pos[1].x, pos[1].y);
	}
}

Vector2 Bezier::bezierCurve(float t) const
{
	return pow((1 - t), 3) * p0 + 3 * pow((1 - t), 2) * t * p1 + 3 * (1 - t) * pow(t, 2) * p2 + pow(t, 3) * p3;
}
