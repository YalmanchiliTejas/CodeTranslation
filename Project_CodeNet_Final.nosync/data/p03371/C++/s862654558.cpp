#include <bits/stdc++.h>
using namespace std;
#define rep(i,n,x) for(int i=n;i<x;i++)
using ll = long long;

int main() {
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

	ll ans = 0;
	while (x > 0 && y > 0) {
		if (a + b >= c * 2) ans += c * 2;
		else ans += a + b;
		x--; y--;
	}
	rep(i, 0, x) ans += min(a, c * 2);
	rep(i, 0, y) ans += min(b, c * 2);

	cout << ans << endl;

	return 0;
}