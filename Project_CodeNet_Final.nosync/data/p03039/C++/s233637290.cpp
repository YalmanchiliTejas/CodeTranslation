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
//const ll MOD = 1000000007;
const ll INF = 1LL << 60;
const int INF_INT = 1 << 30;

struct Fast {
	Fast() {
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast; //cin,cout�������̂��܂��Ȃ��{�����w��

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
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
ll mll::MOD = (ll)(1e9 + 7);// 998244353LL;//(ll)(1e9 + 7);


//AtCoder Beginner Contest 127 - E
int main() {
	mll N;
	scanf("%lld", &N.val);
	mll M;
	scanf("%lld", &M.val);
	mll K;
	scanf("%lld", &K.val);

	mll sum = 0;
	rep(i, N.val) { 
		mll temp = 0;
		mll row = i;
		temp += (row * (row + 1) / 2);
		row = N - i - 1;
		temp += (row * (row + 1) / 2);

		rep(j, M.val) {
			sum += temp * M;
			mll col = j;
			sum += N * (col * (col + 1) / 2);
			col = M - j - 1;
			sum += N * (col * (col + 1) / 2);
		}
	}

	sum /= 2;

	mll result = sum * mll::Combination(N.val * M.val, K.val);
	result *= mll::Combination(K.val, 2);
	result /= mll::Combination(N.val * M.val, 2);

	printf("%lld\n", result.val);
}
