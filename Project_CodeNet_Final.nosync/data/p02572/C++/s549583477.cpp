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
#define debug(x) cerr << __LINE__ << ' ' << #x << ':' << x << '\n'
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr int mod = 1000000007;
constexpr int mod998 = 998244353;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
constexpr ll ten(int n) { return n ? 10 * ten(n - 1) : 1; };
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }
template<class T> istream &operator >> (istream &s, vector<T> &v) { for (auto &e : v) s >> e; return s; }
template<class T> ostream &operator << (ostream &s, const vector<T> &v) { for (auto &e : v) s << e << ' '; return s; }

struct fastio {
	fastio() {
		cin.tie(0); cout.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(20);
		cerr << fixed << setprecision(20);
	}
}fastio_;

template <int mod> class modint {
	int n;
public:
	modint() : n(0) {};
	modint(ll n_) {
		n = n_ % mod;
		if (n < 0) n += mod;
	}
	modint operator -() const { return n > 0 ? mod - n : -n; }
	bool operator == (const modint &m) const { return n == m.n; }
	bool operator != (const modint &m) const { return n != m.n; }
	modint &operator += (const modint &m) { n += m.n; if (n >= mod) n -= mod; return *this; }
	modint &operator -= (const modint &m) { n -= m.n; if (n < 0) n += mod; return *this; }
	modint &operator *= (const modint &m) { n = ll(n) * m.n % mod; return *this; }
	modint &operator /= (const modint &m) { n = ll(n) * m.inv().n % mod; return *this; }
	modint operator +(modint m) const { return modint(*this) += m; }
	modint operator -(modint m) const { return modint(*this) -= m; }
	modint operator *(modint m) const { return modint(*this) *= m; }
	modint operator /(modint m) const { return modint(*this) /= m; }
	modint &operator ++ () { *this += 1; return *this; }
	modint operator ++ (int) { *this += 1; return *this - 1; }
	modint &operator -- () { *this -= 1; return *this; }
	modint operator -- (int) { *this -= 1; return *this + 1; }
	modint inv() const {
		return (*this).pow(mod - 2);
	}
	modint pow(ll b) const {
		modint res = 1, a = modint(*this);
		while (b) {
			if (b & 1) res *= a;
			a *= a;
			b >>= 1;
		}
		return res;
	}
	friend istream &operator >> (istream &s, modint<mod> &a) { s >> a.n; return s; }
	friend ostream &operator << (ostream &s, modint<mod> &a) { s << a.n; return s; }
};

using mint = modint<mod>;

signed main() {
	int n;
	cin >> n;
	vector<mint> a(n);
	rep(i, n) cin >> a[i];
	mint sum = 0;
	rep(i, n) sum += a[i];
	mint ans = sum * sum;
	rep(i, n) ans -= a[i] * a[i];
	ans /= 2;
	cout << ans << '\n';
}