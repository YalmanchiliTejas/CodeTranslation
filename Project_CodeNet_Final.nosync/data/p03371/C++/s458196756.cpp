#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (x > y) {
		int t = x;
		x = y;
		y = t;
		t = a;
		a = b;
		b = t;
	}

	int ans = y * c * 2;
	ans = min(ans, x * c * 2 + (y - x) * b);
	ans = min(ans, a * x + b * y);
	cout << ans << endl;

	return 0;
}