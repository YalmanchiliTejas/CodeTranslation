#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = 0;
	int before = min(a + b, 2 * c);
	if (x <= y) {
		ans += before * x;
		int after = min(b, 2 * c);
		ans += after * (y - x);
	}
	else {
		ans += before * y;
		int after = min(a, 2 * c);
		ans += after * (x - y);
	}
	cout << ans << endl;
	return 0;
}