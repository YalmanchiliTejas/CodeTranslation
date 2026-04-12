#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exp(ll x, ll k, ll mod) {
	if (k == 0)
		return 1;
	if (k%2 == 1)
		return x*exp(x, k-1, mod)%mod;
	ll y = exp(x, k/2, mod);
	return y*y%mod;
}

ll n, m, binom[3005][3005], s[3005][3005], e2[10005], e22[10000005];

int main() {
	cin >> n >> m;
	for (int i = 0; i < 3005; ++i)
		for (int j = 0; j <= i; ++j) {
			if (j == 0)
				binom[i][j] = 1;
			else
				binom[i][j] = (binom[i-1][j] + binom[i-1][j-1])%m;
		}

	e2[0] = 1;
	for (int i = 1; i < 10005; ++i)
		e2[i] = 2*e2[i-1]%(m-1);
	e22[0] = 1;
	for (int i = 1; i < 10000005; ++i)
		e22[i] = 2*e22[i-1]%m;
	
	for (int i = 0; i < 3005; ++i)
		for (int j = 0; j <= i; ++j) {
			if (j == 0) {
				if (i == 0)
					s[i][j] = 1;
				continue;
			}
			s[i][j] = (j*s[i-1][j] + s[i-1][j-1])%m;
		}

	ll ans = 0;

	for (int j = 0; j <= n; ++j) {
		ll mult = 1;
		if (j%2 == 1)
			mult = m-1;
		mult = mult*binom[n][j]%m;
		//everything grouped
		ll x = exp(2, e2[n-j], m);
		for (int k = 0; k <= j; ++k) {
			ans = (ans + mult*s[j][k]%m*x%m*e22[k*(n-j)])%m;
		}
		//some not full group
		for (int k = 1; k <= j; ++k) {
			ans = (ans + mult*s[j][k]%m*k%m*x%m*e22[(k-1)*(n-j)])%m;
		}

		// cout << ans << endl;
	}

	cout << ans << endl;
}
