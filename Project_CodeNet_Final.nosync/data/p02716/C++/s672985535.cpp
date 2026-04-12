#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <cassert>
#include <array>
#include <memory>
#include <random>
#include <functional>
#include <complex>
#ifdef DEBUG
#include "./Lib/debug.hpp"
#include "./Lib/Timer.hpp"
#include "./Lib/sample.hpp"
#else
#define dump(...)
#endif

/* (=＾o＾=) */
//#define int ll

/* macro */
#define FOR(i, b, e) for(ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for(ll i = (ll)(e-1); i >= (ll)(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPC(x,c) for(const auto& x:(c))
#define REPI2(it,b,e) for(auto it = (b); it != (e); ++it)
#define REPI(it,c) REPI2(it, (c).begin(), (c).end())
#define RREPI(it,c) REPI2(it, (c).rbegin(), (c).rend())
#define REPI_ERACE2(it, b, e) for(auto it = (b); it != (e);)
#define REPI_ERACE(it, c) REPI_ERACE2(it, (c).begin(), (c).end())
#define ALL(x) (x).begin(),(x).end()
#define cauto const auto&
/* macro func */
template<class T>
inline void sort(T& t) { std::sort(ALL(t)); }
template<class T>
inline void rsort(T& t) { std::sort((t).rbegin(), (t).rend()); }
template<class T>
inline void unique(T& t) { (t).erase(unique((t).begin(), (t).end()), (t).end()); }
template<class T, class S>
inline bool chmax(T& t, const S& s) { if (s > t) { t = s; return true; } return false; }
template<class T, class S>
inline bool chmaxE(T& t, const S& s) { if (s >= t) { t = s; return true; } return false; }
template<class T, class S>
inline bool chmin(T& t, const S& s) { if (s < t) { t = s; return true; } return false; }
inline void BR() { std::cout << "\n"; }

/* type define */
using ll = long long;
using PAIR = std::pair<ll, ll>;
using VS = std::vector<std::string>;
using VL = std::vector<long long>;
using VVL = std::vector<VL>;
using VVVL = std::vector<VVL>;
using VD = std::vector<double>;
template<class T>
using V = std::vector<T>;

/* using std */
using std::cout;
constexpr char endl = '\n';
using std::cin;
using std::pair;
using std::string;
using std::stack;
using std::queue;
using std::vector;
using std::list;
using std::map;
using std::unordered_map;
using std::multimap;
using std::unordered_multimap;
using std::set;
using std::unordered_set;
using std::unordered_multiset;
using std::multiset;
using std::bitset;
using std::priority_queue;
using std::tuple;

/* constant value */
constexpr ll MOD = 1000000007;
//constexpr ll MOD = 998244353;
//constexpr ll MOD = 2;

/* Initial processing  */
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

/* Remove the source of the bug */
inline signed pow(signed, signed) { assert(false); return -1; }

/* define hash */
namespace std {
template <>	class hash<std::pair<ll, ll>> { public:	size_t operator()(const std::pair<ll, ll>& x) const { return hash<ll>()(1000000000 * x.first + x.second); } };
}

/* input */
template<class T> std::istream& operator >> (std::istream& is, vector<T>& vec) { for (T& x : vec) is >> x; return is; }

//=============================================================================================

auto evensolve(ll n, const VL& v) {
	VL a(n / 2), b(n / 2);
	REP(i, n) {
		((i & 1) ? b : a)[i / 2] = v[i];
	}
	FOR(i, 1, n / 2) { a[i] += a[i - 1]; }
	RREP(i, n / 2 - 1) { b[i] += b[i + 1]; }
	ll ans = std::max(a[n / 2 - 1], b[0]);
	REP(i, n / 2 - 1) { chmax(ans, a[i] + b[i + 1]); }
	return ans;
}

auto oddSolve(ll n, const VL& v) {
	VVL dp(n, VL(3, -1e18));
	dp[0][0] = v[0];
	dp[1][0] = v[1];
	dp[0][1] = 0;
	dp[1][2] = 0;
	FOR(i, 2, n) REP(j, 3) {
		dp[i][j] = dp[i - 2][j] + v[i];

		if (i - 3 >= 0 && j - 1 >= 0) {
			chmax(dp[i][j], dp[i - 3][j - 1] + v[i]);
		}

		if (i - 4 >= 0 && j - 2 >= 0) {
			chmax(dp[i][j], dp[i - 4][j - 2] + v[i]);
		}
		if (j - 1 >= 0)chmax(dp[i][j], dp[i - 1][j - 1]);
	}
	//dump(dp);

	return std::max(dp[n - 1][1], dp[n - 1][2]);
}

signed main() {
	ll n;
	cin >> n;
	VL v(n);
	cin >> v;


	if (n & 1) {
		ll ans = oddSolve(n, v);
		cout << ans << endl;
	} else {
		ll ans = evensolve(n, v);
		cout << ans << endl;
	}
}


