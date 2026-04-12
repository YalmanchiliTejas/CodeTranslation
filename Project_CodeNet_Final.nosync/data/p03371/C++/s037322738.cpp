#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c, x, y;
	while (cin >> a >> b >> c >> x >> y)
	{
		if ((a + b) / 2.0 > c)
		{
			if (a / 2.0 > c) a = c * 2;
			if (b / 2.0 > c) b = c * 2;
			int d = min(x, y);
			cout << d*c * 2 + (x - d)*a + (y - d)*b << endl;
		}
		else cout << a*x + b*y << endl;
	}
	return 0;
}