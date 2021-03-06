#pragma once

#include "Vector2.h"

class Bezier
{
public:
	Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3);
	void draw(SDL_Renderer *renderer) const;
	Vector2 BezierCurve(float x) const;
	Vector2 BezierCurveTangent(float t) const;
	float GetBezierTangent(float x) const;
	static float GetDistance(Vector2 currentCarVector, Vector2 nextCarVector);

	
private:
	Vector2 p0, p1, p2, p3;
};
