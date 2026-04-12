#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

ll mod;
constexpr ll modsize = 3010;
vector<ll> fac(modsize);
vector<ll> inv(modsize);
vector<ll> facinv(modsize);

void modcalc() {
	if (modsize == 0) abort();
	fac[0] = 1; fac[1] = 1; inv[1] = 1;
	facinv[0] = 1; facinv[1] = 1;
	for (ll i = 2; i < modsize; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
}

ll modinv(ll a ,ll m) {
	if (a == 0) abort();
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

ll modpow(ll a, ll b, ll m) {
	ll ans = 1;
	a %= m;
	while (b) {
		if (b & 1) ans = ans * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}

ll modcomb(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll modperm(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[n - k] % mod;
}

ll modhom(ll n, ll k) {
	if (n < 0 || k < 0 || n == 0 && k > 0) return 0;
	if (n == 0 && k == 0) return 1;
	return fac[n + k - 1] * facinv[k] % mod * facinv[n - 1] % mod;
}

ll dp[3010][3010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	ll n;
	cin >> n >> mod;
	modcalc();
	dp[0][0] = 1;
	for (ll i = 1; i <= n + 1; i++) {
		for (ll j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
			dp[i][j] %= mod;
		}
	}
	ll ans = modpow(2, modpow(2, n, mod - 1), mod);
	for (ll i = 1; i <= n; i++) {
		ll sign = 1;
		if (i & 1) sign = -1;
		ll sum = 0;
		for (ll j = 1; j <= i + 1; j++) {
			sum += dp[i + 1][j] * modpow(2, (n - i)*j, mod) % mod;
			sum %= mod;
		}
		sum *= modinv(modpow(2, (n - i), mod), mod); sum %= mod;
		sum *= modpow(2, modpow(2, (n - i), mod - 1), mod); sum %= mod;
		sum *= modcomb(n, i); sum %= mod;
		sum *= sign; if (sum < 0) sum += mod;
		ans += sum; if (ans >= mod) ans -= mod;
	}
	cout << ans << '\n';
}