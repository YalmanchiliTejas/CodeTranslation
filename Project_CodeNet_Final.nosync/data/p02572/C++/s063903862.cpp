#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	vector<ll> s(n);
	s[0] = a[0];
	for (int i = 1; i < n; i++) {
		s[i] = s[i - 1] + a[i];
	}

	ll ans = 0;
	for (ll i = 0; i < n - 1; i++) {
		ll delta = (a[i] % mod) * ((s[n - 1] - s[i]) % mod);
		delta %= mod;
		ans = (ans + delta) % mod;
	}
	cout << ans << endl;
}
