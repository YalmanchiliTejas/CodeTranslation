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
#ifdef DEBUG
#include "./Lib/debug.hpp"
#include "./Lib/Timer.hpp"
#include "./Lib/sample.hpp"
#else
#define dump(...)
#endif

/* (=＾o＾=) */
#define int ll

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
inline auto sort(T& t) { std::sort(ALL(t)); }
template<class T>
inline auto rsort(T& t) { std::sort((t).rbegin(), (t).rend()); }
template<class T>
inline auto unique(T& t) { (t).erase(unique((t).begin(), (t).end()), (t).end()); }
template<class T, class S>
inline auto chmax(T& t, const S& s) { if (s > t) { t = s; return true; } return false; }
template<class T, class S>
inline auto chmaxE(T& t, const S& s) { if (s >= t) { t = s; return true; } return false; }
template<class T, class S>
inline auto chmin(T& t, const S& s) { if (s < t) { t = s; return true; } return false; }
inline auto BR() { std::cout << "\n"; }

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



signed main() {
	string s;
	cin >> s;
	ll n = s.size();
	ll k;
	cin >> k;
	VL v; v.reserve(n);
	REPC(c, s) { v.emplace_back(c - '0'); }

	if (k == 1) {
		ll ans = (n - 1) * 9;
		ans += v[0];
		cout << ans << endl;
	} else if (k == 2) {
		ll ans = (n - 1) * (n - 2) * 9 * 9 / 2;
		dump(ans);
		ans += (v[0] - 1) * (n - 1) * 9;

		bool b = true;
		FOR(i, 1, n) {
			if (b) {
				ans += v[i];
			} else {
				ans += 9;
			}
			if (v[i] > 0) { b = false; }
		}

		cout << ans << endl;
	} else {

		// o..xxx..
		ll ans = (n - 1) * (n - 2) * (n - 3) * 9 * 9 * 9 / 2 / 3;
		dump(ans);
		// X..xx...
		ans += (v[0] - 1) * (n - 1) * (n - 2) / 2 * 9 * 9;
		dump(ans);
		ll f = 1000;
		ll t = 1000;
		FOR(i, 1, n) {
			if (v[i] > 0) {
				if (f == 1000) { f = i; } else { t = i; break; }
			}
		}
		// xX...x..
		ans += (v[f] - 1) * (n - f - 1) * 9;
		dump(ans);
		// xx ...x...
		if (t < 1000) {
			ans += v[t];
			ans += (n - t - 1) * 9;
		}
		dump(ans);
		// x.xx..
		ans += (n - f - 1) * (n - f - 2) / 2 * 9 * 9;
		cout << ans << endl;
		dump(f, t);

	}
}
