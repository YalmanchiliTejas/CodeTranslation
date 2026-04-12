#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	const ll mod = 1000000007;
	vector<ll> accum(n + 1, 0);
	for (ll i = n; i >= 1; i--) {
		if (i != n) {
			accum[i] += accum[i + 1];
		}
		accum[i] += a[i];
		accum[i] %= mod;
	}
	ll ans = 0;
	for (ll i = 1; i <= n - 1; i++) {
		ans += a[i] * accum[i + 1];
		ans %= mod;
	}
	//ans += a[n - 1] * a[n];
	//ans %= mod;
	cout << ans << endl;
    return 0;
}