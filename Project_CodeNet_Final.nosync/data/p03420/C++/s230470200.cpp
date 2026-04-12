
/*
	@・ω・@
*/

/*****/

/**/
# pragma GCC target("avx")  // CPU 処理並列化
# pragma GCC optimize("O3")  // CPU 処理並列化
# pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
/**/

# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <sstream>
# include <cmath>
# include <queue>
# include <stack>
# include <map>
# include <iomanip>	//cout << fixed << setprecision(桁数);
# include <stdexcept>
# include <functional>
# include <tuple>
# include <set>
# include <bitset>
# include <complex>

//#define int long long

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<long long, long long>;
template<class T> using vec = vector<T>;
template<class T> using grapth = vec<vec<T>>;

#define rep(i, n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i, n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
#define rrep(i, n) for(ll i=(n)-1; i >= 0; --i)
#define rrep1(i, n) for(ll i=(n); i > 0; --i)
#define step(i, a, n) for(ll i=(a), i##_len=(a)+(n); i<i##_len; ++i)
#define rstep(i, a, n) for(ll i=(a)+(n)-1, i##_len=(a); i>=i##_len; --i)
#define range(i, a, b) for(ll i=(a), i##_len=(b); i<i##_len; ++i)
#define rrange(i, a, b) for(ll i=(b)-1, i##_len=(a); i>=i##_len; --i)

constexpr int INF = numeric_limits<int>::max();
constexpr ll INFL = numeric_limits<ll>::max();
constexpr ll INFUL = numeric_limits<ull>::max();

std::string strMulti(const char c, const int n) {
	std::string out = "";
	for (int i = 0; i < n; i++) { out += c; }
	return out;
}
std::string strMulti(const std::string t, const int n) {
	std::string out = "";
	for (int i = 0; i < n; i++) { out += t; }
	return out;
}
std::string tab(const int n)
{
	return strMulti('\t', n);
}
std::string join(const std::vector<std::string>& v, const char* delim = 0) {
	std::string s;
	if (!v.empty()) {
		s += v[0];
		for (decltype(v.size()) i = 1, c = v.size(); i < c; ++i) {
			if (delim) s += delim;
			s += v[i];
		}
	}
	return s;
}

string to_string(string& s) {
	return '"' + s + '"';
}
string to_string(char& c) {
	string out = { '\'', c, '\'' };
	return out;
}
template<class T1, class T2> string to_string(pair<T1, T2> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template<class Tuple, size_t ...I> string _to_string_tuple(Tuple&& t, std::index_sequence<I...>) {
	vector<string> texts = { to_string(std::get<I>(t))... };
	return "(" + join(texts, ", ") + ")";
}
template<class ...Args> string to_string(tuple<Args...> t) {
	using Tuple = tuple<Args...>;
	return _to_string_tuple(std::forward<Tuple>(t),
		std::make_index_sequence<std::tuple_size<std::decay_t<Tuple>>::value>{});
}
template<class T> string to_string(vector<T> ar) {
	vector<string> texts(ar.size());
	for (size_t i = 0; i < ar.size(); ++i)
	{
		texts[i] = to_string(ar[i]);
	}
	return "{" + join(texts, ", ") + "}";
}
template<class T> string to_string(initializer_list<T> il) {
	vector<string> texts(il.size());
	size_t i = 0;
	for (T v : il)
	{
		texts[i] = to_string(v);
		i++;
	}
	return "{" + join(texts, ", ") + "}";
}

#define debugvar(x) debugln(#x, (x))
#define debugvartab(x, t) debugln(tab(t) + #x, (x))
void debug(string name) {
	std::cerr << name;
}
void debugln(string name) {
	std::cerr << name << '\n';
}
template<class T> void debug(string name, T v) {
	std::cerr << name << " = " << to_string(v);
}
template<class T> void debugln(string name, T v) {
	std::cerr << name << " = " << to_string(v) << '\n';
}
template<class T> void debug(string name, initializer_list<T> il) {
	std::cerr << name << " = " << to_string(il);
}
template<class T> void debugln(string name, initializer_list<T> il) {
	std::cerr << name << " = " << to_string(il) << '\n';
}
template<class ...Args> void debug(string name, Args ...args) {
	std::cerr << name << " = " << to_string(tuple<Args...>(args...));
}
template<class ...Args> void debugln(string name, Args ...args) {
	std::cerr << name << " = " << to_string(tuple<Args...>(args...)) << '\n';
}

#define all(x) (x).begin(), (x).end()
#define pair(a, b) make_pair(a, b)

template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, const T b) { if (a > b) { a = b; return true; } return false; }
template<class T> T divup(const T a, const T b) { if (a % b == 0) { return a / b; } return a / b + 1; }
template<class T> bool cmp_2nd(pair<T, T> a, pair<T, T> b) { if (a.second != b.second) { return a.second < b.second; } return a.first < b.first; }
ll mod_pow(ll x, ll n, const ll& p) { ll ret = 1; while (n > 0) { if (n & 1) { (ret *= x) %= p; } (x *= x) %= p; n >>= 1; } return ret; }
template<class T> T modinv(T a, const T& p) { T b = p, u = 1, v = 0; while (b) { T t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); } u %= p; if (u < 0) { u += p; } return u; }
template<class T> T math_P(T m, T n) { T ret = 1; for (T i = m; i > m - n; i--) { ret *= i; } return ret; }
template<class T> T math_C(T m, T n) { T ret = math_P(m, n); for (T i = 2; i <= n; i++) { ret /= i; } return ret; }
ll extended_euclidean(ll u, ll v) { ll r0 = u; ll r1 = v; ll s0 = 1; ll s1 = 0; ll t0 = 0; ll t1 = 1; while (r1 != 0) { ll q = r0 / r1; ll r = r0 - q * r1; ll s = s0 - q * s1; ll t = t0 - q * t1; r0 = r1; s0 = s1; t0 = t1; r1 = r; s1 = s; t1 = t; } if (t0 < 0) { return t0 + u; } else { return t0; } }
ll math_C_mod(ll n, ll c, const ll& p) { ll upe = 1; ll dow = 1; for (ll i = 1; i < c + 1; ++i) { upe = upe * n % p; dow = dow * i % p; n -= 1; } return (upe * extended_euclidean(p, dow)) % p; }
//ll math_P_mod(ll m, ll n, const ll& p) { ll ret = 1; for (ll i = m; i > m - n; i--) { ret = (ret * i) % p; }return ret; }
//ll math_C_mod(ll m, ll n, const ll& p) { ll ret = math_P_mod(m, n, p); ll div = 1; for (ll i = 2; i <= n; i++) { div = (div * i) % p; }ret = (ret * modinv(div, p)) % p; return ret; }
template<class T> T math_gcd(T a, T b) { if (b == 0) { return a; } else { return math_gcd(b, a % b); } }
template<class T> T SumStep(T a, T n, T d) { return n * (2 * a + (n - 1) * d) / 2; }
template<class T> T SumRange(T a, T b, T d) { return SumStep(a, (b - a) / d, d); }

constexpr ll MOD = 1000000007;	// 10^9+7

/*****/

void Main()
{
	ll n, k;
	cin >> n >> k;

	if (k == 0)
	{
		cout << n * n;
		return;
	}

	ll ret = 0;
	range(b, k + 1, n + 1)
	{
		range(a1, k, b)
		{
			ret += (n + 1) / b + ( (n + 1) / b * b + a1 <= n );
		}
	}

	cout << ret;
}

/*****/

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout << std::fixed << std::setprecision(10);

	/**
	while (true)
	{
		Main();
		std::cerr << flush;
		cout << endl;
	}
	/*/
	Main();
	std::cerr << flush;
	std::cout << endl;
	/**/

	return 0;
}
