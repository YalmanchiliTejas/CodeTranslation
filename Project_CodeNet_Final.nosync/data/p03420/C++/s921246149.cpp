#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << (ll)n*n << endl;
		return 0;
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (i <= k)continue;
		ll l = (n + 1) / i;
		ll h = (n + 1) % i;
		ans += l * (i - k) + max((ll)0, h - k);
	}
	cout << ans << endl;
}