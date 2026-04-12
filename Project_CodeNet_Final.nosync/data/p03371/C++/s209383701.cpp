#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c, x, y;
	int price;

	cin >> a >> b >> c >> x >> y;

	if (x > y)
	{
		if (a > 2 * c)
		{
			price = c * 2 * x;
		}
		else if (a + b > 2 * c)
		{
			price = c * 2 * y + a * (x - y);
		}
		else
		{
			price = a * x + b * y;
		}
	}
	else
	{
		if (b > 2 * c)
		{
			price = 2 * y * c;
		}
		else if (a + b > 2 * c)
		{
			price = c * 2 * x + b * (y - x);
		}
		else
		{
			price = a * x + b * y;
		}
	}

	cout << price << endl;
 
	return 0;
}