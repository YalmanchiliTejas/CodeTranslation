#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int a_y, b_y, c_y, x, y;
	cin >> a_y >> b_y >> c_y >> x >> y;

	int minx;
	if (x > y)minx = x*2;
	else minx = y*2;

	int min = 0x7fffffff;
	int noww = 0;

	int j = 0, xi = 0, yi = 0;

	for (int i = 0; i < minx; ++i) {
		j = i * 2;
		xi = (x - i);
		if (xi < 0)xi = 0;
		yi = (y - i);
		if (yi < 0)yi = 0;

		noww = a_y * xi + b_y * yi + c_y * j;
		if (min > noww) min = noww;
	}

	cout << min;

	return 0;
}