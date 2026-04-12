#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = 1000000000;
	//両方普通に買う
	ans = min(ans, (ll)a * x + b * y);
	//一枚あまして買う
	ll k = 2 * c * min(x, y);
	if (x >= y) k += (x - y) * a;
	else k += (y - x) * b;
	ans = min(ans, k);
	//多く買う
	ll h = 2 * c * max(x, y);
	ans = min(ans, h);
	cout << ans << endl;
	return 0;
}