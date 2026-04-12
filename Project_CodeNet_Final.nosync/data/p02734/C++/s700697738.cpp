#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _SILENCE_CXX17_RESULT_OF_DEPRECATION_WARNING
#include "bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rfor(i, m, n) for (int i = (m); i >= (n); --i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define range_it(a, l, r) (a).begin() + (l), (a).begin() + (r)

using namespace std;
using LL = long long;		using ld = long double;
using VB = vector<bool>;	using VVB = vector<VB>;
using VI = vector<int>;		using VVI = vector<VI>;
using VL = vector<LL>;		using VVL = vector<VL>;
using VS = vector<string>;	using VD = vector<double>;
using PII = pair<int, int>;	using VP = vector<PII>;
using PLL = pair<LL, LL>;	using VPL = vector<PLL>;
template<class T>using Grid = vector<vector<T>>;
template<class T>using PQ = priority_queue<T>;
template<class T>using PQS = priority_queue<T, vector<T>, greater<T>>;
constexpr int inf = (int)1e9;
constexpr LL inf_ll = (LL)1e18, MOD = 1000000007;
constexpr ld PI = M_PI, EPS = 1e-12;

template<class T>inline void Sort(T& a)noexcept { sort(all(a)); }
template<class T>inline void RSort(T& a)noexcept { sort(rall(a)); }
template<class T>inline void Reverse(T& a)noexcept { reverse(all(a)); }
template<class T>inline void Unique(T& a)noexcept { a.erase(unique(all(a)), a.end()); }
template<class T>inline T Sorted(T a)noexcept { Sort(a); return a; }
template<class T>inline T RSorted(T a)noexcept { RSort(a); return a; }
template<class T>inline T Reversed(T a)noexcept { Reverse(a); return a; }
template<class T>inline T Uniqued(T a)noexcept { Unique(a); return a; }
template<class T>inline auto Max(const T& a)noexcept { return *max_element(all(a)); }
template<class T>inline auto Min(const T& a)noexcept { return *min_element(all(a)); }
template<class T>inline int MaxPos(const T& a)noexcept { return max_element(all(a)) - a.begin(); }
template<class T>inline int MinPos(const T& a)noexcept { return min_element(all(a)) - a.begin(); }
template<class T, class U>inline int Count(const T& a, const  U& v)noexcept { return count(all(a), v); }
template<class T, class U>inline int Find(const T& a, const U& v)noexcept { return find(all(a), v) - a.begin(); }
template<class T, class U = typename T::value_type>inline U Sum(const T& a)noexcept { return accumulate(all(a), U()); }
template<class T, class U>inline int Lower(const T& a, const U& v)noexcept { return lower_bound(all(a), v) - a.begin(); }
template<class T, class U>inline int Upper(const T& a, const U& v)noexcept { return upper_bound(all(a), v) - a.begin(); }
template<class T, class P>inline void RemoveIf(T& a, P f)noexcept { a.erase(remove_if(all(a), f), a.end()); }
template<class T>inline T Age(T n, T m)noexcept { return (n + m - 1) / m; }
template<class T>inline T Age2(T n, T m)noexcept { return Age(n, m) * m; }
template<class T>inline T Tri(T n)noexcept { return (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1); }
template<class T = long long>inline T BIT(int b)noexcept { return T{ 1 } << b; }
template<class T>inline T Gcd(T n, T m)noexcept { return m ? Gcd(m, n % m) : n; }
template<class T>inline T Lcm(T n, T m)noexcept { return n / Gcd(n, m) * m; }
template<class T, class U = typename T::value_type>inline U Gcd2(const T& v)noexcept { return accumulate(next(v.begin()), v.end(), U(*v.begin()), Gcd<U>); }
template<class T, class U = typename T::value_type>inline U Lcm2(const T& v)noexcept { return accumulate(next(v.begin()), v.end(), U(*v.begin()), Lcm<U>); }
template<class T>inline T Pow(T a, T n)noexcept { T r = 1; while (n > 0) { if (n & 1)r *= a; a *= a; n /= 2; }return r; }
template<class T>inline T Powmod(T a, T n, T m = MOD)noexcept { T r = 1; while (n > 0) { if (n & 1)r = r * a % m, n--; else a = a * a % m, n /= 2; }return r; }
template<class T>inline bool chmax(T& a, const T& b)noexcept { if (a < b) { a = b; return true; } return false; }
template<class T>inline bool chmin(T& a, const T& b)noexcept { if (a > b) { a = b; return true; } return false; }
template<class T>inline bool inRange(const T& v, const T& min, const T& max)noexcept { return min <= v && v <= max; }
inline string operator*(string s, size_t n)noexcept { string ret; rep(i, n)ret += s; return ret; }

// --- input --- //
#if defined(_WIN32) || defined(ONLINE_JUDGE)
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
inline int gc()noexcept { return getchar_unlocked(); }
template<class T>inline void InputF(T& v)noexcept { cin >> v; }
inline void InputF(char& v)noexcept { while (isspace(v = gc())); }
inline void InputF(bool& v)noexcept { char c; InputF(c); v = c == '1'; }
inline void InputF(string& v)noexcept {
	char c; for (InputF(c); !isspace(c); c = gc())v += c;
}
inline void InputF(int& v)noexcept {
	bool neg = false; v = 0; char c; InputF(c);
	if (c == '-') { neg = true; c = gc(); }
	for (; isdigit(c); c = gc())v = v * 10 + (c - '0');
	if (neg)v = -v;
}
inline void InputF(long long& v)noexcept {
	bool neg = false; v = 0; char c; InputF(c);
	if (c == '-') { neg = true; c = gc(); }
	for (; isdigit(c); c = gc())v = v * 10 + (c - '0');
	if (neg)v = -v;
}
inline void InputF(double& v)noexcept {
	double dp = 1; bool neg = false, adp = false; v = 0; char c; InputF(c);
	if (c == '-') { neg = true; c = gc(); }
	for (; isdigit(c) || c == '.'; c = gc()) {
		if (c == '.')adp = true;
		else if (adp)v += (c - '0') * (dp *= 0.1);
		else v = v * 10 + (c - '0');
	}
	if (neg)v = -v;
}
template<class T, class U>inline void InputF(pair<T, U>& v)noexcept {
	InputF(v.first); InputF(v.second);
}
template<class T>inline void InputF(vector<T>& v)noexcept {
	for (auto& e : v)InputF(e);
}
template<class T>inline T InputF() { T v; InputF(v); return v; }
struct InputV {
	int n, m;
	InputV(int N) :n(N), m(0) {}
	InputV(pair<int, int> N) :n(N.first), m(N.second) {}
	template<class T>operator vector<T>()noexcept {
		vector<T> v(n); InputF(v); return v;
	}
	template<class T>operator vector<vector<T>>()noexcept {
		vector<vector<T>> v(n, vector<T>(m)); InputF(v); return v;
	}
};
struct Input {
	template<class T>operator T()noexcept { return InputF<T>(); }
	int operator--(int) { int v; InputF(v); v--; return v; }
	InputV operator[](int n)noexcept { return InputV(n); }
	InputV operator[](pair<int, int> n)noexcept { return InputV(n); }
	void operator()() {}
	template<class H, class...T>void operator()(H&& h, T&& ...t) {
		InputF(h); operator()(forward<T>(t)...);
	}
	template<class T, size_t W>array<vector<T>, W> get(int H) {
		array<vector<T>, W> ret;
		for (int i = 0; i < H; ++i)for (int j = 0; j < W; ++j)ret[j].push_back(InputF<T>());
		return ret;
	}
}in;
#define input(type) InputF<type>()

// --- output --- //
struct BoolStr {
	const char* t, * f; BoolStr(const char* _t, const char* _f) :t(_t), f(_f) {}
}Yes("Yes", "No"), yes("yes", "no"), YES("YES", "NO"), Int("1", "0");
struct DivStr {
	const char* d, * l; DivStr(const char* _d, const char* _l) :d(_d), l(_l) {}
}spc(" ", "\n"), no_spc("", "\n"), end_line("\n", "\n"), comma(",", "\n"), no_endl(" ", "");
class Output {
	BoolStr B{ Yes }; DivStr D{ spc }; bool isPrint = true;
	void p(double v) { printf("%.20f", v); } void p(long double v) { printf("%.20Lf", v); }
	void p(int v) { printf("%d", v); }	void p(LL v) { printf("%lld", v); }
	void p(char v) { putchar(v); }		void p(bool v) { printf("%s", v ? B.t : B.f); }
	template<class T>void p(const T& v) { cout << v; }
	template<class T, class U>void p(const pair<T, U>& v) { p(v.first); printf("%s", D.d); p(v.second); }
	template<class T>void p(const vector<T>& v) { rep(i, sz(v)) { if (i)printf("%s", D.d); p(v[i]); } }
	template<class T>void p(const vector<vector<T>>& v) { rep(i, sz(v)) { if (i)printf("%s", D.l); p(v[i]); } }
	void p(const BoolStr& v) { B = v; isPrint = false; } void p(const DivStr& v) { D = v; isPrint = false; }
public:
	Output& operator()() { printf("%s", D.l); return *this; }
	template<class H>Output& operator()(H&& h) {
		p(h); if (isPrint)printf("%s", D.l); isPrint = true; return *this;
	}
	template<class H, class...T>Output& operator()(H&& h, T&& ...t) {
		p(h); if (isPrint)printf("%s", D.d); isPrint = true; return operator()(forward<T>(t)...);
	}
	template<class...T>void exit(T&& ...t) {
		operator()(forward<T>(t)...); std::exit(EXIT_SUCCESS);
	}
	Output& flush() { cout.flush(); return *this; }
	Output& set_bs(const char* t, const char* f) { B = BoolStr(t, f); return *this; }
}out;

// --- dump --- //
#if __has_include("dump.hpp")
#include "dump.hpp"
#else
#define dump(...) (void(0))
#endif

template<class T>struct Step {
	class It {
		T a, b, c;
	public:
		constexpr It() : a(T()), b(T()), c(T()) {}
		constexpr It(T _b, T _c, T _s) : a(_b), b(_c), c(_s) {}
		constexpr It& operator++() { --b; a += c; return *this; }
		constexpr It operator++(int) { It tmp = *this; --b; a += c; return tmp; }
		constexpr const T& operator*()const { return a; }
		constexpr const T* operator->()const { return &a; }
		constexpr bool operator==(const It& other)const { return b == other.b; }
		constexpr bool operator!=(const It& other)const { return !(b == other.b); }
		constexpr T start()const { return a; }
		constexpr T count()const { return b; }
		constexpr T step()const { return c; }
	};
	constexpr Step(T b, T c, T s) : be(b, c, s) {}
	constexpr It begin()const { return be; }
	constexpr It end()const { return en; }
	constexpr T start()const { return be.start(); }
	constexpr T count()const { return be.count(); }
	constexpr T step()const { return be.step(); }
	operator vector<T>()const { return as_vector(); }
	vector<T> as_vector()const {
		vector<T> res; res.reserve(count());
		each([&](T i) {res.push_back(i); });
		return res;
	}
	template<class F>void each(F f)const { for (T i : *this)f(i); }
	template<class F>auto map(F f)const {
		vector<decay_t<result_of_t<F(T)>>> res; res.reserve(count());
		each([&](T i) {res.push_back(f(i)); });
		return res;
	}
	template<class F>int count_if(F f)const {
		int res = 0; each([&](T i) {i += f(i); }); return res;
	}
	template<class F>vector<T> select(F f)const {
		vector<T> res; each([&](T i) {if (f(i))res.push_back(i); }); return res;
	}
	template<class F>auto sum(F f)const {
		decay_t<result_of_t<F(T)>> res = 0; each([&](T i) {res += f(i); }); return res;
	}
	using value_type = T;
	using iterator = It;
private:
	It be, en;
};
template<class T>inline constexpr auto step(T a) { return Step<T>(0, a, 1); }
template<class T>inline constexpr auto step(T a, T b) { return Step<T>(a, b - a, 1); }
template<class T>inline constexpr auto step(T a, T b, T c) { return Step<T>(a, (b - a - 1) / c + 1, c); }

template<class F>inline auto MakeVector(size_t size, F f) {
	vector<decay_t<result_of_t<F(size_t)>>> res(size);
	for (size_t i = 0; i < size; ++i)res[i] = f(i);
	return res;
}
template<class T>inline auto Slice(const T& v, size_t i, size_t len) {
	return i < v.size() ? T(v.begin() + i, v.begin() + min(i + len, v.size())) : T();
}
template<class T, class F>inline void Each(T& v, F f) {
	for (auto& e : v)f(e);
}
template<class T, class F>inline auto Map(const T& v, F f) {
	vector<decay_t<result_of_t<F(typename T::value_type)>>> res(v.size());
	size_t i = 0; for (const auto& e : v)res[i++] = f(e);
	return res;
}
template<class T, class F>inline auto MapIndex(const T& v, F f) {
	vector<decay_t<result_of_t<F(size_t, typename T::value_type)>>> res(v.size());
	size_t i = 0; for (auto it = v.begin(); it != v.end(); ++it, ++i)res[i] = f(i, *it);
	return res;
}
template<class T, class F>inline auto Select(const T& v, F f) {
	T res;
	for (const auto& e : v)if (f(e))res.push_back(e);
	return res;
}
template<class T, class F>inline auto TrueIndex(const T& v, F f) {
	vector<size_t> res;
	size_t i = 0; for (const auto& e : v) { if (f(e))res.push_back(i); ++i; }
	return res;
}
template<class T, class F>inline auto Sum(const T& v, F f) {
	return accumulate(next(v.begin()), v.end(), f(v.front()), [&](auto a, auto b) {return a + f(b); });
}

// ---------------------------------------------------------------- //

template<int MOD>struct modint {
	using T = long long;
	T n;
	constexpr modint(const T x = 0)noexcept :n(x% MOD) { if (n < 0)n += MOD; }
	constexpr int get_mod()const noexcept { return MOD; }
	constexpr modint operator+()const noexcept { return *this; }
	constexpr modint operator-()const noexcept { return n ? MOD - n : 0; }
	constexpr modint& operator++()noexcept { if (MOD <= ++n)n = 0; return *this; }
	constexpr modint& operator--()noexcept { if (n <= 0)n = MOD; n--; return *this; }
	constexpr modint& operator++(int)noexcept { modint t = *this; ++* this; return t; }
	constexpr modint& operator--(int)noexcept { modint t = *this; --* this; return t; }
	constexpr modint next()const noexcept { modint t = *this; ++t; return t; }
	constexpr modint pred()const noexcept { modint t = *this; --t; return t; }
	constexpr modint operator+(const modint& m)const noexcept { return modint(*this) += m; }
	constexpr modint operator-(const modint& m)const noexcept { return modint(*this) -= m; }
	constexpr modint operator*(const modint& m)const noexcept { return modint(*this) *= m; }
	constexpr modint operator/(const modint& m)const noexcept { return modint(*this) /= m; }
	constexpr modint& operator+=(const modint& m)noexcept {
		n += m.n; if (n >= MOD)n -= MOD; return *this;
	}
	constexpr modint& operator-=(const modint& m)noexcept {
		n -= m.n; if (n < 0)n += MOD; return *this;
	}
	constexpr modint& operator*=(const modint& m)noexcept {
		n = n * m.n % MOD; return *this;
	}
	constexpr modint& operator/=(const modint& m)noexcept {
		assert(m.n);
		T a = m.n, b = MOD, u = 1, v = 0;
		while (b) {
			T t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		n = n * u % MOD;
		if (n < 0)n += MOD;
		return *this;
	}
	constexpr bool operator==(const modint& m)const noexcept { return n == m.n; }
	constexpr bool operator!=(const modint& m)const noexcept { return n != m.n; }
	constexpr modint pow(modint m)const noexcept {
		modint t = n, res = 1;
		while (m.n > 0) { if (m.n & 1)res *= t; t *= t; m.n >>= 1; }
		return res;
	}
	constexpr modint operator^(modint m)const noexcept { return pow(m); }
};
using mint = modint<998244353>;
using VM = vector<mint>;
template<int MOD>ostream& operator<<(ostream& os, const modint<MOD>& m)noexcept { return os << m.n; }
template<int MOD>istream& operator>>(istream& is, modint<MOD>& m)noexcept { return is >> m.n; }
mint operator""_m(unsigned long long n) { return n; }

int main() {
	int n = in, s = in;
	VI a = in[n];

	mint ans;
	VM dp(3009);
	dp[0] = 1;
	rep(i, n) {
		VM dp2 = dp;
		dp2[a[i]] += i + 1;
		FOR(j, 1, 3005)if (dp[j] != 0 && j + a[i] < 3008) {
			dp2[j + a[i]] += dp[j];
		}
		dp = dp2;
		ans += dp[s];
	}
	out(ans);
}