#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	c *= 2;
	a = min(a, c);
	b = min(b, c);
	ll ans = 0;
	if (a + b >= c) {
		if (x > y) {
			ans += c * y;
			x -= y;
			y = 0;
		}
		else {
			ans += c * x;
			y -= x;
			x = 0;
		}
	}
	ans += a * x + b * y;
	cout << ans << endl;
	return 0;
}