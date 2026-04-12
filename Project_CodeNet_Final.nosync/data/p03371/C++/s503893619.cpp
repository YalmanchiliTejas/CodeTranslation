#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, x, y, r = 1000000000, z;
	cin >> a >> b >> c >> x >> y;
	
	for (int i = 0; i <= 2 * max(x, y); i++)
	{
		z = i * c + a * (i >= 2 * x ? 0 : (2 * x - i) / 2 + (2 * x - i) % 2) + b * (i >= 2 * y ? 0 : (2 * y - i) / 2 + (2 * y - i) % 2);
		r = min(r, z);
	}	
	
	cout << r;
}