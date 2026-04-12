#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (a + b > 2 * c) {
		int z = min(x, y);
		x -= z;
		y -= z;
		int sum = 2 * z * c;
		if (x > 0) {
			if (a > 2 * c) sum += 2 * x * c;
			else sum += x * a;
		}
		if (y > 0) {
			if (b > 2 * c) sum += 2 * y * c;
			else sum += y * b;
		}
		cout << sum << '\n';
	} else cout << a * x + b * y << '\n';
	return 0;
}
