#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	ll mod = 7 + 1e9;
	ll n, ans = 0;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i,n) {
		cin >> a[i];
		if (i != 0) b[i] += b[i - 1] + a[i];
	}
	rep(i,n) {
		ll k = a[i] * ((b[n - 1] - b[i]) % mod) % mod;
		ans += k;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
