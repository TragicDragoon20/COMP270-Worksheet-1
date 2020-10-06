#include "stdafx.h"
#include "Bezier.h"
#include "cmath" // Used to help calculate radians to degrees

Bezier::Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3)
	: p0(p0), p1(p1), p2(p2), p3(p3)
{
}

void Bezier::draw(SDL_Renderer *renderer) const
{
	// Value used to determine the accuracy of the bezier curve
	const int numOfLineSegments = 20;
	
	for (float i = 0; i < numOfLineSegments; i++)
	{
		// Creates a vector2 array to add 2 points to that are used to draw lines between the two points
		Vector2 pos[] =
		{
			BezierCurve(i / numOfLineSegments),
			BezierCurve((i + 1) / numOfLineSegments)
		};
		// Draws a line determined by the vector2 array
		SDL_RenderDrawLineF(renderer, pos[0].x, pos[0].y, pos[1].x, pos[1].y);
	}
}


// Used to calculate points along the bezier curve for each value of t
Vector2 Bezier::BezierCurve(float t) const
{
	return pow((1 - t), 3) * p0 + 3 * pow((1 - t), 2) * t * p1 + 3 * (1 - t) * pow(t, 2) * p2 + pow(t, 3) * p3;
}

// Used to calculate the tangents of the bezier curve for each value of t
Vector2 Bezier::BezierCurveTangent(float t) const
{
	return (3 * pow(1 - t, 2) * (p1 - p0)) + (6 * (1 - t) * t * (p2 - p1)) + (3 * pow(t, 2) * (p3 - p2));
}


// used to calculate the angle of each tangent and convert to degrees
float Bezier::GetBezierTangent(float x) const
{
	const Vector2 tangentVector = BezierCurveTangent(x);
	const float rad = atan2f(tangentVector.y, tangentVector.x);
	return rad * (180.f / M_PI);
}