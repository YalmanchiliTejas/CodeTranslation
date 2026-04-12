#include "bits/stdc++.h"

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define ll long long
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>istream &operator>>(istream &is, pair<T, S> &p) { is >> p.first >> p.second; return is; }
//template <typename T, typename S>ostream &operator<<(ostream &os, pair<T, S> &p) {os << p.first << " " << p.second;return os;}

template <typename T> void printvv(const vector<vector<T>> &v) {
	cerr << endl;
	rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
		if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
			cerr << "INF";
		}
		else
			cerr << v[i][j];
		cerr << (j == v[i].size() - 1 ? '\n' : ' ');
	}
	cerr << endl;
}

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
template <class T, class U>bool chmin(T& a, U b) { if (a > b) { a = b; return true; }return false; }
template <class T, class U>bool chmax(T& a, U b) { if (a < b) { a = b; return true; }return false; }
template <int MOD> struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) {
		int sigt = sig % MOD;
		if (sigt < 0)
			sigt += MOD;
		x = sigt;
	}
	ModInt(signed long long sig) {
		int sigt = sig % MOD;
		if (sigt < 0)
			sigt += MOD;
		x = sigt;
	}
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) {
		if ((x += that.x) >= MOD)
			x -= MOD;
		return *this;
	}
	ModInt &operator-=(ModInt that) {
		if ((x += MOD - that.x) >= MOD)
			x -= MOD;
		return *this;
	}
	ModInt &operator*=(ModInt that) {
		x = (unsigned long long)x * that.x % MOD;
		return *this;
	}
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b;
			std::swap(a, b);
			u -= t * v;
			std::swap(u, v);
		}
		if (u < 0)
			u += MOD;
		ModInt res;
		res.x = (unsigned)u;
		return res;
	}
};
template <int MOD> ostream &operator<<(ostream &os, const ModInt<MOD> &m) {
	return os << m.x;
}
template <int MOD> istream &operator>>(istream &is, ModInt<MOD> &m) {
	signed long long s;
	is >> s;
	m = ModInt<MOD>(s);
	return is;
};
// pow(mint(2), 1000) のように
template <int MOD> ModInt<MOD> pow(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1)
			r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

//#define int long long を使っても大丈夫
using mint = ModInt<1000000007>;

// 5は1e9+7の原始根
// return g^x=a mod p
int modlog(int g, int a) {
	// g is a primitive root modulo mint::Mod
	// let x = i*n + j , n = sqrt(Mod)
	// g^j = a*inv(g^(i*n)) = a*(inv(g^n))^i
	//https://en.wikipedia.org/wiki/Baby-step_giant-step
	//http://sonickun.hatenablog.com/entry/2016/11/20/192743
	//https://cp-algorithms.com/algebra/discrete-log.html
	unordered_map<int, int> M;
	int n = sqrt(mint::Mod);
	ll cur = 1;
	for (int i = 0; i < n; i++, (cur *= g) %= mint::Mod) {
		M[cur] = i;
	}
	ll gn = cur;
	ll gn_inv = mint(gn).inverse().get();
	cur = 1;
	ll num = 0;
	while (1) {
		ll x = a * cur % mint::Mod;
		if (M.count(x)) return num + M[x];
		cur = cur * gn_inv%mint::Mod;
		num += n;
	}
}
int modlog(int g, mint a) { return modlog(g, a.get()); }


// nCrで用いる
vector<mint> fact, factinv;
// nCrで用いる 予め計算しておく
void nCr_compute_factinv(int N) {
	N = min(N, mint::Mod - 1);
	fact.resize(N + 1);
	factinv.resize(N + 1);
	fact[0] = 1;
	rep(i, 1, N + 1) fact[i] = fact[i - 1] * i;
	factinv[N] = fact[N].inverse();
	for (int i = N; i >= 1; i--)
		factinv[i - 1] = factinv[i] * i;
}
mint nCr(int n, int r) {
	if (n >= mint::Mod)
		return nCr(n % mint::Mod, r % mint::Mod) *
		nCr(n / mint::Mod, r / mint::Mod);
	return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}

mint nHr(int n, int r) { return r == 0 ? 1 : nCr(n + r - 1, r); }
//http://maicommon.ciao.jp/ss/dscrtMath2/Cataran/index.htm
mint catalan(int n) { return nCr(2 * n, n) / (n + 1); }



signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);


	int n, m, k; cin >> n >> m >> k;
	nCr_compute_factinv(n*m + 1);
	vector<vector<mint>>dp(n, vector<mint>(m));
	vector<vector<mint>>dp2(n, vector<mint>(m));
	dp[0][0] = 0;
	dp2[0][0] = 2;
	rep(i, 1, n) {
		dp[i][0] = dp[i - 1][0] + i;
		dp2[i][0] = dp2[i - 1][0] + i + 2;
	}
	rep(i, 1, m) {
		dp[0][i] = dp[0][i-1]+i;
		dp2[0][i] = dp2[0][i-1]+2 + i;
	}
	rep(i, 1, n) {
		rep(j, 1, m) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + i + j;
			dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1] - dp2[i - 1][j - 1] + i + j + 2;

		}
	}
	mint ans = 0;
	rep(i, 0, n) {
		rep(j, 0, m) {
			mint x = dp[n - 1 - i][m - 1 - j];
			if (i + 1 < n and j - 1 >= 0) {
				x += dp2[n - 1 - (i + 1)][j - 1];
			}
			x *= nCr(n*m - 2, k - 2);
			ans += x;
		}
	}
	cout << ans << endl;


	return 0;
}
