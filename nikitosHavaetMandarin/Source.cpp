#include "triangle.h"
#include "point.h"
#include <iostream>
#include "fstream"
#include <vector>

double sum(int** points, int** seq, int n, int k)
{
	triangle* tr = new triangle[k];

	for (int i = 0; i < k; i++)
	{
		point* temp = new point[3];
		for (int j = 0; j < 3; j++)
		{
			int s = seq[i][j];
			temp[j] = point(points[s - 1][0], points[s - 1][1]);
		}

		tr[i] = triangle(temp[0], temp[1], temp[2]);
	}
	double res=0;
	for (int i = 0; i < k; i++)
		res += tr[i].area();
	return res;
}


int main()
{
	std::ifstream f;

	f.open("nikita.txt");

	int n;
	f >> n;
	int** points = new int* [n];
	for (int i = 0; i < n; i++)
		points[i] = new int[2];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			f >> points[i][j];
			//std::cout << points[i][j] << " ";
		}
		//std::cout << std::endl;
	}

	int k;
	f >> k;
	//std::cout << k << std::endl;
	int** seq = new int* [k];
	for (int i = 0; i < k; i++)
		seq[i] = new int[3];


	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			f >> seq[i][j];
			//std::cout << seq[i][j] << " ";
		}
		//std::cout << std::endl;
	}
	std::cout<< sum(points, seq, n, k);

	return 0;
}