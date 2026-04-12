#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = 0;
	if (a + b > 2 * c) {
		int mi = min(x, y);
		x -= mi;
		y -= mi;
		ans += 2 * mi * c;
		if (x > 0 && a > 2 * c) {
			ans += 2 * c * x;
		}
		else if (y > 0 && b > 2 * c) {
			ans += 2 * c * y;
		}
		else {
			ans += a * x + b * y;
		}
	}
	else {
		ans += a * x + b * y;
	}
	cout << ans << endl;
	

	return 0;
}