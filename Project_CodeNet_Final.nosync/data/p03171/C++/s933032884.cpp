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

#define int ll; // ＾o＾

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
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort((x).rbegin(),(x).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define BR cout<<"\n";
#define cauto const auto&

#define dump(...) { auto __DUMP_NAME_LIST__ = split(#__VA_ARGS__,','); print(__DUMP_NAME_LIST__, __VA_ARGS__);BR;}


using ll = long long;
using PAIR = std::pair<ll, ll>;
using VS = std::vector<std::string>;
using VL = std::vector<long long>;
using VD = std::vector<double>;
// using VI = std::vector<int>;
// using VVI = std::vector<std::vector<int>>;
using VVL = std::vector<std::vector<ll>>;

using std::cout;
// using std::endl;
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

constexpr ll MOD = 1000000007;
//constexpr ll MOD = 998244353;
constexpr ll INF = 1LL << 60;
const double PI = std::acos(-1.0);

template<class T> std::istream& operator >> (std::istream& is, vector<T>& vec) { for (T& x : vec) is >> x; return is; }
template<class S, class T>std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
inline std::list<std::string> split(std::string str, char del) { std::list<std::string> sList; string s = ""; for (const auto& c : str) { if (c == del) { sList.emplace_back(s); s = ""; } else { if (c != ' ' || del == ' ') { s += c; } } }sList.emplace_back(s);	return sList; }
struct Preprocessing { Preprocessing() { std::cin.tie(0); std::ios::sync_with_stdio(0); }; };

template<class T>struct has_begin { private:	template <class U>	static auto check(U x) -> decltype(x.begin(), std::true_type{});	static std::false_type check(...); public:	static bool const value = decltype(check(std::declval<T>()))::value; };
inline void print(std::list<std::string>& str); template<class Primitive, class... Tail, std::enable_if_t<!has_begin<Primitive>::value, std::nullptr_t> = nullptr>inline void print(std::list<std::string>& str, const Primitive& x, const Tail&... tail); template<class Container, class... Tail>inline auto print(std::list<std::string>& str, const Container& c, const Tail&... tail) -> decltype(c.begin()); template<class... Tail>inline void print(std::list<std::string>& str, const std::string& s, const Tail&... tail);
template<class Container>inline auto printSingle(const Container& c) ->decltype(c.begin()) { for (const auto& x : c) { std::cout << x << " "; }std::cout << "\n"; return c.begin(); }
template<class Primitive, std::enable_if_t<!has_begin<Primitive>::value, std::nullptr_t> = nullptr>inline void printSingle(const Primitive& x) { std::cout << x << " "; }
inline void print(std::list<std::string>& str) {}
template<class Primitive, class... Tail, std::enable_if_t<!has_begin<Primitive>::value, std::nullptr_t> = nullptr>inline void print(std::list<std::string>& str, const Primitive& x, const Tail&... tail) { std::cout << *str.begin() << ":" << x << " "; if (sizeof...(tail) > 0) { std::cout << "\n"; str.pop_front(); print(str, tail...); } }
template<class Container, class... Tail>inline auto print(std::list<std::string>& str, const Container& c, const Tail&... tail) ->decltype(c.begin()) { std::cout << "-- " << *str.begin() << " --\n"; for (const auto& x : c) { printSingle(x); BR; }std::cout << "\n"; str.pop_front();	print(str, tail...); return c.begin(); }
template<class... Tail>inline void print(std::list<std::string>& str, const std::string& s, const Tail&... tail) { std::cout << *str.begin() << ":" << s << "\n"; str.pop_front();	print(str, tail...); }


//=============================================================================================

// ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
// ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// ll pow(ll a, ll b) { ll ans = 1; while (b > 0) { if (b % 2 == 1) { ans *= a; ans %= MOD; }b /= 2; a *= a; a %= MOD; }return ans; }
// ll comb(ll a, ll b) { static constexpr ll size = 1e6; static VL fac(size); static VL finv(size); static VL inv(size); static ll n = 0; if (n > a) { return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD; }fac[0] = fac[1] = 1; finv[0] = finv[1] = 1; inv[1] = 1; FOR(i, 2, a + 1) { inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD; fac[i] = fac[i - 1] * (ll)i%MOD; finv[i] = finv[i - 1] * inv[i] % MOD; }n = a + 1; return comb(a, b); }
// multiset<ll> prime_decomposition(ll n) { ll i = 2; multiset<ll> table{}; while (i * i <= n) { while (n % i == 0) { n /= i;	table.emplace(i); }++i; }if (n > 1) { table.emplace(n); return table; }return table; }
// vector<bool> eratosthenes(ll n) { vector<bool> lst(n + 1, true); lst[0] = lst[1] = false; FOR(i, 2, n / 2 + 1) { lst[i * 2] = false; }for (ll i = 3; i <= n; i += 2) { if (lst[i] == false) { continue; }FOR(j, 2, n / i + 1) { lst[i*j] = false; } }return lst; }

//==============================================================================================

signed main() {
	ll n;
	cin >> n;
	VL v(n);
	cin >> v;

	VVL dp(n, VL(n));
	REP(i, n) {
		dp[i][i] = v[i] * ((n % 2) ? 1 : -1);
	}
	FOR(k, 2, n + 1)REP(i, n - k + 1) {
		if ((n + k) % 2) {
			dp[i][i + k - 1] = std::min(dp[i + 1][i + k - 1] - v[i],
										dp[i][i + k - 2] - v[i + k - 1]);
		} else {
			dp[i][i + k - 1] = std::max(dp[i + 1][i + k - 1] + v[i],
										dp[i][i + k - 2] + v[i + k - 1]);
		}
	}
	cout << dp[0][n - 1] << endl;
	//dump(dp);
}