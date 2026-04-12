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
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000010;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

constexpr ll mod = 1000000007;
constexpr ll modsize = 0;
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

ll modinv(ll a) {
	if (a == 0) abort();
	ll b = mod, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}

ll modpow(ll a, ll b) {
	ll ans = 1;
	a %= mod;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
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

vector<ll> a(100);

P solve(ll l, ll r, ll d) {
	ll s = inf;
	for (int i = l; i < r; i++) chmin(s, a[i]);
	ll dp1 = 1, dp2 = 2;
	for (int i = l; i < r; i++) {
		if (a[i] == s) {
			if (i != l && a[i - 1] != s) {
				P p = solve(l, i, s);
				ll pf = p.first; ll ps = p.second;
				dp1 *= (pf + ps); dp1 %= mod;
				dp2 *= ps; dp2 %= mod;
			}
			l = i + 1;
			dp1 *= 2; dp1 %= mod;
		}
	}
	if (l < r) {
		P p = solve(l, r, s);
		ll pf = p.first; ll ps = p.second;
		dp1 *= (pf + ps); dp1 %= mod;
		dp2 *= ps; dp2 %= mod;
	}
	dp1 += dp2 * modpow(2, s - d - 1) - dp2 + mod; dp1 %= mod;
	dp2 *= modpow(2, s - d - 1); dp2 %= mod;
	return P(dp1, dp2);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	rep(i, n) cin >> a[i];
	cout << solve(0, n, 0).first << '\n';
}