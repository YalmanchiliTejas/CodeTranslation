#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int inv[2005];
ll qpow(ll a, ll n = mod - 2) {
	ll res = 1;
	while (n)
	{
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

ll C(ll m, ll n) {
	//if (m < 0 || n < 0 || n < m) return 0;
	ll r = 1;
	for (int i = 1; i <= m; ++i) {
		r = (n - i + 1) % mod * r % mod * inv[i] % mod;
	}
	return r;
}
int main() {
	ll n, x, d;
	for (int i = 1; i < 2005; ++i)
		inv[i] = (int)qpow(i);
	while (cin >> n >> d >> x, n) {
		ll ans = 0;
		for (ll i = 0; i <= n / x && i <= d; ++i) {
			ll a = C(i, d);
			ll b = C(n - i * x, n - i * x + d - 1);
			ll flag = (i & 1) ? -1 : 1;
			ans = (ans + flag * a * b % mod) % mod;
		}
		cout << (ans + mod) % mod << endl;
	}
	return 0;
}
