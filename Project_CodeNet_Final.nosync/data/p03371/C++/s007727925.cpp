#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int main(void)
{
	int a, b, c, x, y;

	cin >> a >> b >> c >> x >> y;

	int xy = a * x + b * y;

	int big = max(x, y);

	int half = c * big * 2;

	int x_num = x;
		int y_num = y;
		int h = 0;
		int best = xy;

		while (true)
		{
			if (x_num != 0)
			{
				x_num--;
			}
			if (y_num != 0)
			{
				y_num--;
			}
			h += 2;

			int ans = a * x_num + b * y_num + c * h;

			if (ans > best)
			{
				cout << best << endl;
				return 0;
			}

			best = ans;
		}

	return 0;
}