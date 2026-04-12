#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll mod(ll a) {
	return (a % MOD + MOD) % MOD;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; ++i)cin >> a[i];
	vector<ll> r(n, 0);
	r[0] = a[0];
	for (ll i = 1; i < n; ++i)r[i] = mod(r[i - 1] + a[i]);
	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		ll sum = mod(a[i] * mod(r.back() - r[i]));
		ans += sum;
		ans %= MOD;
	}
	cout << ans << endl;
}
