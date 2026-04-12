#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	int ans = 0;
	if (a + b >= 2 * c) {
		ans += min(x, y) * 2 * c;
		if (x > y)x -= y, y = 0;
		else y -= x, x = 0;

		if (x)ans += min(a, 2 * c) * x;
		if (y)ans += min(b, 2 * c) * y;
	}
	else {
		ans += a * x + b * y;
	}
	cout << ans << endl;

	return 0;
}