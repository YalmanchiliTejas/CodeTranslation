#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MaxN = 1e5;


int a, b, c, x, y;

int main()
{
	cin >> a >> b >> c >> x >> y;
	if(a + b > 2 * c)
	{
		if(x > y)
		{
			if(a > 2 * c)
				cout << 2 * c * x << endl;
			else 
			cout << (2 * c * y) + (x - y) * a << endl;
		}
		else
		{
			if(b> 2 * c)
				cout << 2 * c * y << endl;
			else
			cout << (2 * c * x) + (y - x) * b << endl;
		}
	}
	else  cout << x * a + b * y << endl;
}

