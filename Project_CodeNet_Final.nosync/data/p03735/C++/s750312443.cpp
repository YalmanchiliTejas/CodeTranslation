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

/* (=＾o＾=) */
// #define int ll

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
#define SORT(x) do{sort(ALL(x));}while(false)
#define RSORT(x) do{sort((x).rbegin(),(x).rend());}while(false)
#define UNIQUE(v) do{v.erase( unique(v.begin(), v.end()), v.end() );}while(false)
#define MAX(x,y) do{x = std::max(x,y);}while(false)
#define MIN(x,y) do{x = std::min(x,y);}while(false)
#define BR do{cout<<"\n";}while(false)
#define dump(...) do{ auto __DUMP_NAME_LIST__ = split(#__VA_ARGS__,','); print(__DUMP_NAME_LIST__, __VA_ARGS__);BR;}while(false)

/* type define */
using ll = long long;
using PAIR = std::pair<ll, ll>;
using VS = std::vector<std::string>;
using VL = std::vector<long long>;
using VVL = std::vector<VL>;
using VVVL = std::vector<VVL>;
using VD = std::vector<double>;

/* using std */
using std::cout;
constexpr char endl = '\n';
using std::cin;
using std::sort;
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

/* constant value */
constexpr ll MOD = 1000000007;
//constexpr ll MOD = 998244353;

/* Initial processing  */
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; }_Preprocessing;

/* input output */
template<class T> std::istream& operator >> (std::istream& is, vector<T>& vec) { for (T& x : vec) is >> x; return is; }
template<class S, class T>std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; }

/* for dump function */
inline std::list<std::string> split(std::string str, char del) { std::list<std::string> sList; string s = ""; for (const auto& c : str) { if (c == del) { sList.emplace_back(s); s = ""; } else { if (c != ' ' || del == ' ') { s += c; } } }sList.emplace_back(s);	return sList; }
template<class T>struct has_begin { private:	template <class U>	static auto check(U x) -> decltype(x.begin(), std::true_type{});	static std::false_type check(...); public:	static bool const value = decltype(check(std::declval<T>()))::value; };
inline void print(std::list<std::string>& str); template<class Primitive, class... Tail, std::enable_if_t<!has_begin<Primitive>::value, std::nullptr_t> = nullptr>inline void print(std::list<std::string>& str, const Primitive& x, const Tail&... tail); template<class Container, class... Tail>inline auto print(std::list<std::string>& str, const Container& c, const Tail&... tail) -> decltype(c.begin()); template<class... Tail>inline void print(std::list<std::string>& str, const std::string& s, const Tail&... tail);
template<class Container>inline auto printSingle(const Container& c) ->decltype(c.begin()) { for (const auto& x : c) { std::cout << x << " "; }std::cout << "\n"; return c.begin(); }
template<class Primitive, std::enable_if_t<!has_begin<Primitive>::value, std::nullptr_t> = nullptr>inline void printSingle(const Primitive& x) { std::cout << x << " "; }
inline void print(std::list<std::string>& str) {}
template<class Primitive, class... Tail, std::enable_if_t<!has_begin<Primitive>::value, std::nullptr_t> = nullptr>inline void print(std::list<std::string>& str, const Primitive& x, const Tail&... tail) { std::cout << *str.begin() << ":" << x << " "; if (sizeof...(tail) > 0) { std::cout << "\n"; str.pop_front(); print(str, tail...); } }
template<class Container, class... Tail>inline auto print(std::list<std::string>& str, const Container& c, const Tail&... tail) ->decltype(c.begin()) { std::cout << "-- " << *str.begin() << " --\n"; for (const auto& x : c) { printSingle(x); BR; }std::cout << "\n"; str.pop_front();	print(str, tail...); return c.begin(); }
template<class... Tail>inline void print(std::list<std::string>& str, const std::string& s, const Tail&... tail) { std::cout << *str.begin() << ":" << s << "\n"; str.pop_front();	print(str, tail...); }

//=============================================================================================


signed main() {
	ll n;
	cin >> n;
	vector<PAIR> v;
	v.reserve(n);

	ll maxItr = 0;
	ll minItr = 0;
	ll max = 0;
	ll min = 1e10;

	REP(i, n) {
		ll a, b;
		cin >> a >> b;
		if (a > b) { std::swap(a, b); }
		v.emplace_back(a, b);
		if (maxItr == minItr) {
			if (b <= max && a == min) { minItr = i; continue; }
			if (a >= min && b == max) { maxItr = i; continue; }
		}
		if (b > max) { maxItr = i; max = b; }
		if (a < min) { minItr = i; min = a; }

	}

	ll ans = 1e18;
	if (maxItr != minItr) {
		// 同じ
		vector<bool> isChange(n);
		isChange[maxItr] = true;
		isChange[minItr] = true;
		// val. itr
		std::priority_queue<PAIR, vector<PAIR>, std::greater<PAIR>> q;
		ll qmax = 0, qmin = 1e10;
		REP(i, n) {
			ll val = ((i == minItr) ? v[i].second : v[i].first);
			MAX(qmax, val);
			MIN(qmin, val);
			q.emplace(PAIR(val, i));
		}
		MIN(ans, (qmax - qmin)*(max - min));
		while (!q.empty()) {
			auto val = q.top().first;
			auto itr = q.top().second;
			if (isChange[itr]) { break; }
			q.pop();
			isChange[itr] = true;
			auto newVal = v[itr].second;
			q.emplace(PAIR(newVal, itr));
			qmin = q.top().first;
			MAX(qmax, newVal);
			MIN(ans, (qmax - qmin)*(max - min));
		}
	}
	{
		// 違う
		ll lmin = min, lmax = 0;
		ll rmin = 1e10, rmax = max;
		REPC(p, v) {
			MAX(lmax, p.first);
			MIN(rmin, p.second);
		}
		MIN(ans, (lmax - lmin)*(rmax - rmin));
	}

	cout << ans << endl;
}