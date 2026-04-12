#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
#define reps(i, S, E) for (ll i = (S); i <= (E); i++)
#define rep(i, N) reps(i, 0, N-1)
#define deps(i, E, S) for (ll i = (E); i >= (S); i--)
#define dep(i, N) deps(i, N-1, 0)
const ll INF = 1LL << 60;
const int INF_INT = 1 << 30;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
#define CEIL(x, y) ((x + y - 1) / (y))
struct mll {
	static ll MOD;
	ll val;
	mll(ll v = 0) : val(v % MOD) { if (val < 0) val += MOD; }
	mll operator - () const { return -val; }
	mll operator + (const mll &b) const { return val + b.val; }
	mll operator - (const mll &b) const { return val - b.val; }
	mll operator * (const mll &b) const { return val * b.val; }
	mll operator / (const mll &b) const { return mll(*this) /= b; }
	mll operator + (ll b) const { return *this + mll(b); }
	mll operator - (ll b) const { return *this - mll(b); }
	mll operator * (ll b) const { return *this * mll(b); }
	friend mll operator + (ll a, const mll &b) { return b + a; }
	friend mll operator - (ll a, const mll &b) { return -b + a; }
	friend mll operator * (ll a, const mll &b) { return b * a; }
	mll &operator += (const mll &b) { val = (val + b.val) % MOD; return *this; }
	mll &operator -= (const mll &b) { val = (val + MOD - b.val) % MOD; return *this; }
	mll &operator *= (const mll &b) { val = (val*b.val) % MOD; return *this; }
	mll &operator /= (const mll &b) {
		ll c = b.val, d = MOD, u = 1, v = 0;
		while (d) {
			ll t = c / d;
			c -= t * d; swap(c, d);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	mll &operator += (ll b) { return *this += mll(b); }
	mll &operator -= (ll b) { return *this -= mll(b); }
	mll &operator *= (ll b) { return *this *= mll(b); }
	mll &operator /= (ll b) { return *this /= mll(b); }
	bool operator == (const mll &b) { return val == b.val; }
	bool operator != (const mll &b) { return val != b.val; }
	bool operator == (ll b) { return *this == mll(b); }
	bool operator != (ll b) { return *this != mll(b); }
	friend bool operator == (ll a, const mll &b) { return mll(a) == b.val; }
	friend bool operator != (ll a, const mll &b) { return mll(a) != b.val; }
	friend ostream &operator << (ostream &os, const mll &a) { return os << a.val; }
	friend istream &operator >> (istream &is, mll &a) { return is >> a.val; }
	static mll Combination(ll a, ll b) {
		chmin(b, a - b);
		if (b < 0) return mll(0);
		mll c = 1;
		rep(i, b) c *= a - i;
		rep(i, b) c /= i + 1;
		return c;
	}
};
using vmll = std::vector<mll>;
using vvmll = std::vector<vmll>;
using vvvmll = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;

struct Fast {
	Fast() {
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast; //cin,cout高速化のおまじない＋桁数指定

ll mll::MOD = (ll)(1e9 + 7);// 998244353ll;


//--for debug--
#ifdef LOCAL
void _debug_out_(string s = "") {
	if (s != "") { eprintf(s.c_str()); }
	else { eprintf("\n"); }
}
void _debug_out_(ll x, string s = "") {
	if (s != "") { eprintf(s.c_str(), x); }
	else { eprintf("%lld\n", x); }
}
void _debug_out_(mll x, string s = "") {
	if (s != "") { eprintf(s.c_str(), x); }
	else { eprintf("%lld\n", x.val); }
}
void _debug_out_(vvll x, string s = "") {
	string t = s;
	ll maxLen = 0;
	if (s == "") {
		rep(i, (ll)x.size()) rep(j, (ll)x[i].size()) {
			if (x[i][j] == -INF) {
				chmax(maxLen, 1ll);
			}
			else {
				ll n = x[i][j] / 10, len = 1;
				while (n > 0) { len++; n /= 10; }
				chmax(maxLen, len);
			}
		}
		t = "%" + to_string(maxLen) + "lld ";
	}
	rep(i, (ll)x.size()) { rep(j, (ll)x[i].size()) { if (x[i][j] == -INF) { rep(k, maxLen - 1) { eprintf(" "); } eprintf("- "); } else { eprintf(t.c_str(), x[i][j]); } } eprintf("\n"); }
	eprintf("\n");
}
void _debug_out_(vll x, string s = "") {
	rep(i, (ll)x.size()) { if (s != "") { eprintf(s.c_str(), x[i]); } else { eprintf("%lld ", x[i]); } }
	eprintf("\n");
}
void _debug_out_(vector<bool> x) {
	rep(i, (ll)x.size()) { eprintf("%s", x[i] ? "o" : "x"); }
	eprintf("\n");
}
void _debug_out_(vector<vector<bool>> x) {
	rep(i, (ll)x.size()) { rep(j, (ll)x[i].size()) { eprintf("%s", x[i][j] ? "o" : "x"); } eprintf("\n"); }
	eprintf("\n");
}
void _debug_out_(map<ll, ll> x) {
	auto begin = x.begin(), end = x.end();
	for (auto iter = begin; iter != end; iter++) { eprintf("%lld:%lld ", iter->first, iter->second); }
	eprintf("\n");
}
void _debug_out_(map<char, ll> x) {
	auto begin = x.begin(), end = x.end();
	for (auto iter = begin; iter != end; iter++) { eprintf("%c:%lld ", iter->first, iter->second); }
	eprintf("\n");
}
#define debug_out(...) _debug_out_(__VA_ARGS__)
#else
#define debug_out(...) 42
#endif
//!--for debug--


void solve() {
	ll N;
	cin >> N;
	vector<ll> A(N + 2);
	rep(i, N) {
		cin >> A[i + 2];
	}

	bool odd = N % 2 == 0 ? false : true;

	vvll dp(N + 2, vll(3, -INF)); //[iまで考慮][j個skipした状態]

	dp[0][0] = 0;

	reps(i, 2, N + 1) {
		//skip0->0
		if (dp[i - 2][0] != -INF) {
			chmax(dp[i][0], dp[i - 2][0] + A[i]);
		}

		//skip0->1
		chmax(dp[i][1], dp[i - 1][0]);
		if (i >= 3) {
			if (dp[i - 3][0] != -INF) {
				chmax(dp[i][1], dp[i - 3][0] + A[i]);
			}
		}

		//skip0->2
		chmax(dp[i][2], dp[i - 2][0]);
		if (i >= 4) {
			if (dp[i - 4][0] != -INF) {
				chmax(dp[i][2], dp[i - 4][0] + A[i]);
			}
		}

		//skip1->1
		if (i >= 2) {
			if (dp[i - 2][1] != -INF) {
				chmax(dp[i][1], dp[i - 2][1] + A[i]);
			}
		}

		//skip1->2
		chmax(dp[i][2], dp[i - 1][1]);
		if (i >= 3) {
			if (dp[i - 3][1] != -INF) {
				chmax(dp[i][2], dp[i - 3][1] + A[i]);
			}
		}

		//skip2->2
		if (i >= 2) {
			if (dp[i - 2][2] != -INF) {
				chmax(dp[i][2], dp[i - 2][2] + A[i]);
			}
		}
	}

	debug_out(dp);

	ll result = 0;

	if (odd) {
		result = dp[N + 1][2];
	}
	else {
		result = dp[N + 1][1];
	}

	cout << result << endl;
}

int main() {
#if TEST && LOCAL
	ll t; cin >> t;
	rep(i, t) { solve(); }
#else
	solve();
#endif
	return 0;
}
