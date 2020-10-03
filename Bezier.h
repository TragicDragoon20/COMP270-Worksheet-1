#pragma once

#include "Vector2.h"

class Bezier
{
public:
	Bezier(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3);
	Vector2 bezierCurve(float x) const;

	void draw(SDL_Renderer *renderer) const;
private:
	Vector2 p0, p1, p2, p3;

	
};
