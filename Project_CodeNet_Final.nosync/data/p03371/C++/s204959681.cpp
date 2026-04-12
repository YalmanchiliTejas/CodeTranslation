#include <bits/stdc++.h>
using namespace std;

#define int long long

int a, b, c, x, y, ans;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c >> x >> y;
	
	int tmp = min(x, y);
	ans += min(2 * tmp * c, tmp * (a + b));
	x -= tmp;
	y -= tmp;
	cout << ans + min(x * a, 2 * x * c) + min(y * b, 2 * y * c) << endl;
}