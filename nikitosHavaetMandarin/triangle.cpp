#include "triangle.h"
#include <math.h>

triangle::triangle(point p1, point p2, point p3)
{
	this->p1 = p1; this->p2 = p2; this->p3 = p3;
}

triangle::triangle()
{
}

double triangle::area()
{
	double res = (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2;
	if (res < 0)
		res *= -1;
	
	return res;
}

