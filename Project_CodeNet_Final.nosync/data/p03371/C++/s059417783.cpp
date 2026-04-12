#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int AtoB, AB, ZAB;
	AtoB = a * x + b * y;
	AB = 2 * min(x, y) * c + (x >= y?a*(x-y):b*(y-x));
	ZAB = 2 * max(x, y) * c;
	cout << min(AtoB, min(AB, ZAB)) << endl;
	return 0;
}