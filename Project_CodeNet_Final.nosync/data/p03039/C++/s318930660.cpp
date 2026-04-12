#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;

ll mpow(ll a, ll b) {
	ll res = 1;
	a %= mod;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
vector<int> fac, finv;
void factor(int N) {
	fac.resize(N); finv.resize(N);
	fac[0] = finv[0] = 1;
	rep(i, 1, N)fac[i] = 1LL * fac[i - 1] * i % mod;
	finv[N - 1] = mpow(fac[N - 1], mod - 2);
	for (int i = N - 2; i; --i) finv[i] = 1LL * finv[i + 1] * (i + 1) % mod;
}
int nCr(int n, int m) {
	if (m < 0 || n < m) return 0;
	return 1LL * (1LL * fac[n] * finv[m] % mod) * finv[n - m] % mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	factor(200010);
	ll ans = (1LL*(m * m)%mod * (n - 1) * n * (n + 1) / 6) % mod;
	ans = (ans+1LL * (n * n) % mod * (m - 1) * m * (m + 1) / 6) % mod;
	ans = (1LL * ans * nCr(n * m - 2, k - 2)) % mod;
	printf("%lld", ans);
	return 0;
}