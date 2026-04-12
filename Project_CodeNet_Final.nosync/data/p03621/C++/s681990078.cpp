#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll p = 998244353;

string a, b;
int k, s, val[10005][10005];
ll fact[10005], invfact[10005];

ll exp(ll x, ll k) {
	if (k == 0)
		return 1;
	if (k%2 == 1)
		return x*exp(x, k-1)%p;
	ll y = exp(x, k/2);
	return y*y%p;
}

ll inv(ll x) { return exp(x, p-2); }

ll binom(ll x, ll y) {
	if (x < 0 || y < 0 || x < y)
		return 0;
	return fact[x]*invfact[y]%p*invfact[x-y]%p;
}

int main() {
	cin >> a >> b;
	for (int i = 0; i < a.length(); ++i) {
		k += (a[i] - '0');
		s += (a[i] - '0')*(b[i] - '0');
	}

	s = k-s;

	for (int i = 0; i < 10005; ++i) {
		if (i == 0)
			fact[i] = invfact[i] = 1;
		else {
			fact[i] = i*fact[i-1]%p;
			invfact[i] = inv(fact[i]);
		}
	}

	for (int i = 0; i < 10005; ++i)
		for (int j = 0; j < 10005; ++j) {
			if (i == 0 && j == 0) {
				val[i][j] = 1;
				continue;
			} if (i > 0) {
				val[i][j] = (val[i][j] + 1LL*i*i*val[i-1][j])%p;
			} if (j > 0) {
				val[i][j] = (val[i][j] + 1LL*i*j*val[i][j-1])%p;
			}
		}

	ll ans = 0;

	for (int t = 0; t <= k-s; ++t) {
		ans = (ans + binom(k, s+t)*val[s][t]%p*fact[k-s-t]%p*fact[k-s-t]%p*binom(k-s, t));
		ans %= p;
	}

	cout << ans << endl;
}