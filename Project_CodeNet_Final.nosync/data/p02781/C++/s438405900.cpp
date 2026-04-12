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


int main() {
	string N;
	cin >> N;
	ll len_N = N.size();
	ll K;
	cin >> K;

	vvvll dp(len_N + 1, vvll(2, vll(4, 0)));

	// 0以上n以下の整数の個数(=n+1)を求める
	// dp[i][j][k] i:頭からi桁目、j:未満フラグ(0ならn未満であることが確定している)、k:ゼロ以外の数がk個(0～3)
	int x0 = N[0] - '0'; // 0桁目の数字を取り出す
	dp[0][0][0] = 1; // 未満フラグ0となるのは0～x0-1、そのうちゼロ以外が0個なのは、ゼロのときだけ
	dp[0][0][1] = max(0, x0 - 1); // 未満フラグ0となるのは0～x0-1、そのうちゼロ以外が1個なのは、1～x0-1
	dp[0][1][0] = 0; // 未満フラグが1(最初の桁がx0と一致)となるのはx0だけで、これはゼロ以外
	dp[0][1][1] = 1; // 未満フラグが1(最初の桁がx0と一致)となるのはx0だけで、これはゼロ以外

	reps(i, 1, len_N - 1) {
		int x = N[i] - '0'; // i桁目の数字を取り出す

		//◆ゼロ以外が0個
		dp[i][0][0] = dp[i - 1][0][0]; //i-1桁目まででn未満であることが確定。i桁目は0～9どれでもよく、ゼロ以外が0個の個数はゼロを選んだときだけ
		dp[i][1][0] = 0; //i-1桁目までnと一致しているということは、すでにゼロ以外が選ばれているので必ずゼロ個

		if (x > 0) {
			//◆ゼロ以外が1個
			//i桁目まででn未満であることが確定する場合
			dp[i][0][1] =
				dp[i - 1][0][0] * 9 //i-1桁目まででn未満であることが確定。i桁目は0～9どれでもよく、そのうちゼロ以外は9個
				//+ dp[i - 1][1][0] //i-1桁目までnと一致しているということは、すでにゼロ以外が選ばれているので必ずゼロ個
				+ dp[i - 1][0][1] //i-1桁目まででn未満であることが確定。i桁目に0を選んだときだけゼロの個数が増えない(1→1)
				+ dp[i - 1][1][1]; //i-1桁目までnと一致。i桁目に0を選んだときだけゼロの個数が増えない(1→1)

			//i桁目までnと一致する場合
			dp[i][1][1] = 0;
				//+ dp[i - 1][1][0] //i-1桁目までnと一致しているということは、すでにゼロ以外が選ばれているので必ずゼロ個
				//dp[i - 1][1][1]; //i-1桁目までnと一致。ゼロ以外の数が増えないのはゼロを選んだときだけ。xを選ぶと一致が継続しない

			//◆ゼロ以外が2個
			//i桁目まででn未満であることが確定する場合
			dp[i][0][2] =
				dp[i - 1][0][1] * 9 //i-1桁目まででn未満であることが確定。i桁目は0～9どれでもよく、そのうちゼロ以外は9個
				+ dp[i - 1][1][1] * max(0, x - 1) //i-1桁目までnと一致。x未満1以上の数を選ぶと、この桁でn未満であることが確定する
				+ dp[i - 1][0][2] //i-1桁目まででn未満であることが確定。i桁目に0を選んだときだけゼロの個数が増えない(2→2)
				+ dp[i - 1][1][2]; //i-1桁目までnと一致。i桁目に0を選んだときだけゼロの個数が増えない(2→2)。この桁でゼロ未満が確定

			//i桁目までnと一致する場合
			dp[i][1][2] =
				dp[i - 1][1][1]; //i-1桁目までnと一致。xを選ぶとゼロ以外の数が1→2となりn一致が継続
				//+ dp[i - 1][1][2]; //i-1桁目までnと一致。ゼロ以外の数が増えないのはゼロを選んだときだけ。xを選ぶと一致が継続しない

			//◆ゼロ以外が3個
			//i桁目まででn未満であることが確定する場合
			dp[i][0][3] =
				dp[i - 1][0][2] * 9 //i-1桁目まででn未満であることが確定。i桁目は0～9どれでもよく、そのうちゼロ以外は9個
				+ dp[i - 1][1][2] * max(0, x - 1) //i-1桁目までnと一致。x未満1以上の数を選ぶと、この桁でn未満であることが確定する
				+ dp[i - 1][0][3] //i-1桁目まででn未満であることが確定。i桁目に0を選んだときだけゼロの個数が増えない(3→3)
				+ dp[i - 1][1][3]; //i-1桁目までnと一致。i桁目に0を選んだときだけゼロの個数が増えない(3→3)。この桁でゼロ未満が確定

			//i桁目までnと一致する場合
			dp[i][1][3] =
				dp[i - 1][1][2]; //i-1桁目までnと一致。xを選ぶとゼロ以外の数が2→3となりn一致が継続
				//+ dp[i - 1][1][3]; //i-1桁目までnと一致。ゼロ以外の数が増えないのはゼロを選んだときだけ。xを選ぶと一致が継続しない
		}
		else {
			// xがゼロ

			//◆ゼロ以外が1個
			//i桁目まででn未満であることが確定する場合
			dp[i][0][1] =
				dp[i - 1][0][0] * 9 //i-1桁目まででn未満であることが確定。i桁目は0～9どれでもよく、そのうちゼロ以外は9個
				//+ dp[i - 1][1][0] //i-1桁目までnと一致しているということは、すでにゼロ以外が選ばれているので必ずゼロ個
				+ dp[i - 1][0][1]; //i-1桁目まででn未満であることが確定。i桁目に0を選んだときだけゼロの個数が増えない(1→1)
				//+ dp[i - 1][1][1]; //ゼロを選んでもn未満が確定しない

			//i桁目までnと一致する場合
			dp[i][1][1] =
				//+ dp[i - 1][1][0] //i-1桁目までnと一致しているということは、すでにゼロ以外が選ばれているので必ずゼロ個
				dp[i - 1][1][1]; //i-1桁目までnと一致。ゼロしか選べないのでゼロの個数はそのまま

			//◆ゼロ以外が2個
			//i桁目まででn未満であることが確定する場合
			dp[i][0][2] =
				dp[i - 1][0][1] * 9 //i-1桁目まででn未満であることが確定。i桁目は0～9どれでもよく、そのうちゼロ以外は9個
				//+ dp[i - 1][1][1] //i-1桁目までnと一致。この桁は0しか選べず、この桁でn未満は確定しない
				+ dp[i - 1][0][2]; //i-1桁目まででn未満であることが確定。i桁目に0を選んだときだけゼロの個数が増えない(2→2)
				//+ dp[i - 1][1][2]; //ゼロを選んでもn未満が確定しない

			//i桁目までnと一致する場合
			dp[i][1][2] =
				//+ dp[i - 1][1][1] //i-1桁目までnと一致。ゼロしか選べず、ゼロ以外の数は増えない
				dp[i - 1][1][2]; //i-1桁目までnと一致。ゼロしか選べないのでゼロの個数はそのまま

			//◆ゼロ以外が3個
			//i桁目まででn未満であることが確定する場合
			dp[i][0][3] =
				dp[i - 1][0][2] * 9 //i-1桁目まででn未満であることが確定。i桁目は0～9どれでもよく、そのうちゼロ以外は9個
				//+ dp[i - 1][1][2] //i-1桁目までnと一致。この桁は0しか選べず、この桁でn未満は確定しない
				+ dp[i - 1][0][3]; //i-1桁目まででn未満であることが確定。i桁目に0を選んだときだけゼロの個数が増えない(3→3)
				//+ dp[i - 1][1][3]; //ゼロを選んでもn未満が確定しない

			//i桁目までnと一致する場合
			dp[i][1][3] =
				//+ dp[i - 1][1][2] //i-1桁目までnと一致。ゼロしか選べず、ゼロ以外の数は増えない
				dp[i - 1][1][3]; //i-1桁目までnと一致。ゼロしか選べないのでゼロの個数はそのまま
		}
	}

	rep(i, len_N) {
		eprintf("\n%lld\n", i);

		rep(j, 2) {
			rep(k, 4) {
				eprintf("%lld ", dp[i][j][k]);
			}
			eprintf("\n");
		}
		eprintf("\n");
	}

	ll result = dp[len_N - 1][0][K] + dp[len_N - 1][1][K];

	cout << result << endl;

	return 0;
}
