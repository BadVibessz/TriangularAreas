#pragma once
#include "point.h"
class triangle
{
public:
	point p1, p2, p3;
	triangle(point p1, point p2, point p3);
	triangle();
	double area();

};

