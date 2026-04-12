#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#if defined(_MSC_VER) || defined(ONLINE_JUDGE)
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
using LL = long long;		using VB = vector<bool>;
using VI = vector<int>;		using VL = vector<LL>;
using VS = vector<string>;	using VD = vector<double>;
using VVI = vector<VI>;		using VVL = vector<VL>;
using PII = pair<int, int>;	using PLL = pair<LL, LL>;
using VP = vector<PII>;		using VPL = vector<PLL>;
const int inf = (int)1e9;
const LL inf_ll = (LL)1e18, MOD = 1000000007;
const double PI = acos(-1.0), EPS = 1e-12;

template<class T>void Sort(T& a) { sort(all(a)); }
template<class T>void RSort(T& a) { sort(rall(a)); }
template<class T>void Reverse(T& a) { reverse(all(a)); }
template<class T>void Unique(T& a) { a.erase(unique(all(a)), a.end()); }
template<class T>T Sorted(T a) { Sort(a); return a; }
template<class T>T RSorted(T a) { RSort(a); return a; }
template<class T>T Reversed(T a) { Reverse(a); return a; }
template<class T>T Uniqued(T a) { Unique(a); return a; }
template<class T>auto Max(const T& a) { return *max_element(all(a)); }
template<class T>auto Min(const T& a) { return *min_element(all(a)); }
template<class T>int MaxPos(const T& a) { return max_element(all(a)) - a.begin(); }
template<class T>int MinPos(const T& a) { return min_element(all(a)) - a.begin(); }
template<class T, class U>int Count(const T& a, const  U& v) { return count(all(a), v); }
template<class T, class U>int Find(const T& a, const U& v) { auto pos = find(all(a), v); return pos == a.end() ? -1 : pos - a.begin(); }
template<class T, class U>U Sum(const T& a, const U& v) { return accumulate(all(a), v); }
template<class T, class U>int Lower(const T& a, const U& v) { return lower_bound(all(a), v) - a.begin(); }
template<class T, class U>int Upper(const T& a, const U& v) { return upper_bound(all(a), v) - a.begin(); }
template<class T, class P>void RemoveIf(T& a, P f) { a.erase(remove_if(all(a), f), a.end()); }
template<class T>T Age(T n, T m) { return (n + m - 1) / m; }
template<class T>T Gcd(T n, T m) { return m ? Gcd(m, n % m) : n; }
template<class T>T Lcm(T n, T m) { return n / Gcd(n, m) * m; }
template<class T>T Pow(T a, T n) { T r = 1; while (n > 0) { if (n & 1)r *= a; a *= a; n /= 2; }return r; }
template<class T>T Powmod(T a, T n, T m = MOD) { T r = 1; while (n > 0) { if (n & 1)r = r * a % m, n--; else a = a * a % m, n /= 2; }return r; }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T>bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
string operator*(string s, int n) { string ret; rep(i, n)ret += s; return ret; }

// --- input --- //
template<class T>T InputF() { T ret; cin >> ret; return ret; }
template<> char InputF() {
	char ret = '\0', c = getchar_unlocked();
	while (c != '\0' && c != '\n' && c != '\t' && c != ' ') { ret = c; c = getchar_unlocked(); }
	return ret;
}
template<> string InputF() {
	string ret; char c = getchar_unlocked();
	while (c != '\0' && c != '\n' && c != '\t' && c != ' ') { ret.push_back(c); c = getchar_unlocked(); }
	return ret;
}
template<> int InputF() {
	int ret = 0; bool neg = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while (isdigit(c)) { ret = ret * 10 + (c - '0'); c = getchar_unlocked(); }
	return neg ? -ret : ret;
}
template<> LL InputF() {
	LL ret = 0; bool neg = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while (isdigit(c)) { ret = ret * 10LL + (LL(c) - LL('0')); c = getchar_unlocked(); }
	return neg ? -ret : ret;
}
template<> double InputF() {
	double ret = 0, dp = 1; bool neg = false, adp = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while (isdigit(c) || c == '.') {
		if (c == '.')adp = true;
		else if (adp)ret += (c - '0') * (dp *= 0.1);
		else ret = ret * 10.0 + (c - '0');
		c = getchar_unlocked();
	}
	return neg ? -ret : ret;
}
string GetLine() {
	string ret; char c = getchar_unlocked();
	while (c != '\0' && c != '\n') { ret.push_back(c); c = getchar_unlocked(); }
	return ret;
}
struct Input {
	struct InputV {
		int n, m;
		InputV(int N) :n(N), m(-1) {}
		InputV(pair<int, int> N) { tie(n, m) = N; }
		template<class T>operator vector<T>() {
			vector<T> ret(n); rep(i, n)ret[i] = InputF<T>(); return ret;
		}
		template<class T>operator vector<vector<T>>() {
			assert(m != -1); vector<vector<T>> ret(n, vector<T>(m));
			rep(i, n)rep(j, m)ret[i][j] = InputF<T>();
			return ret;
		}
	};
	template<class T>operator T() { return InputF<T>(); }
	InputV operator[](int t) { return InputV(t); }
	InputV operator[](pair<int, int> t) { return InputV(t); }
}in;

// --- output --- //
struct BoolStr {
	const char* t, * f; BoolStr(const char* _t, const char* _f) :t(_t), f(_f) {}
}Yes("Yes", "No"), yes("yes", "no"), YES("YES", "NO"), Int("1", "0");
struct DivStr {
	const char* d, * l; DivStr(const char* _d, const char* _l) :d(_d), l(_l) {}
}spc(" ", "\n"), no_spc("", "\n"), end_line("\n", "\n"), comma(",", "\n"), no_endl(" ", "");
class Print {
	BoolStr B{ Yes }; DivStr D{ spc };	void p(double v) { printf("%.20f", v); }
	void p(int v) { printf("%d", v); }	void p(LL v) { printf("%lld", v); }
	void p(char v) { putchar(v); }		void p(bool v) { printf(v ? B.t : B.f); }
	template<class T>void p(const T& v) { cout << v; }
	template<class T, class U>void p(const pair<T, U>& v) { p(v.first); printf(D.d); p(v.second); }
	template<class T>void p(const vector<T>& v) { rep(i, sz(v)) { if (i)printf(D.d); p(v[i]); } }
	template<class T>void p(const vector<vector<T>>& v) { rep(i, sz(v)) { if (i)printf(D.l); p(v[i]); } }
	void p(const BoolStr& v) { B = v; } void p(const DivStr& v) { D = v; }
	template<class T>bool isPrint(const T& v) { return !is_same<BoolStr, T>::value && !is_same<DivStr, T>::value; }
public:
	void operator()() { printf(D.l); }
	template<class H>void operator()(H&& h) {
		p(h); if (isPrint(h))printf(D.l); B = Yes; D = spc;
	}
	template<class H, class...T>void operator()(H&& h, T&& ...t) {
		p(h); if (isPrint(h))printf(D.d); operator()(forward<T>(t)...);
	}
}out;

// --- step --- //
class step {
	struct It {
		int x, s; It(int _x, int _s) :x(_x), s(_s) { assert(s); }
		int operator*() { return x; } void operator++() { x += s; }
		bool operator!=(It& i) { return 0 < s ? x < i.x : x >= i.x; }
	}; int x, y, s;
public:
	step(int _y, int _s = 1) :x(0 < _s ? 0 : _y), y(0 < _s ? _y : 0), s(_s) {}
	step(int _x, int _y, int _s) :x(_x), y(_y), s(_s) {}
	It begin() { return { x,s }; } It end() { return { y,s }; }
};

struct Point {
	int x, y;
	static const vector<Point> d;
	Point(int _x = -1, int _y = -1) :x(_x), y(_y) {}
	Point(int val, int h, int w) :x(val% w), y(val / w) {}
	Point operator+()const { return *this; }
	Point operator-()const { return { -x,-y }; }
	Point operator+(Point p)const { return { x + p.x,y + p.y }; }
	Point operator-(Point p)const { return { x - p.x,y - p.y }; }
	Point operator*(Point p)const { return { x * p.x,y * p.y }; }
	Point operator/(Point p)const { return { x / p.x,y / p.y }; }
	Point operator+(int d)const { return { x + d,y + d }; }
	Point operator-(int d)const { return { x - d,y - d }; }
	Point operator*(int d)const { return { x * d,y * d }; }
	Point operator/(int d)const { return { x / d,y / d }; }
	Point& operator+=(Point p) { x += p.x; y += p.y; return *this; }
	Point& operator-=(Point p) { x -= p.x; y -= p.y; return *this; }
	Point& operator*=(Point p) { x *= p.x; y *= p.y; return *this; }
	Point& operator/=(Point p) { x /= p.x; y /= p.y; return *this; }
	bool operator==(Point p)const { return x == p.x && y == p.y; }
	bool operator!=(Point p)const { return x != p.x || y != p.y; }
	int Dist(Point p)const { return abs(x - p.x) + abs(y - p.y); }
	bool inRange(int H, int W)const { return 0 <= x && x < W && 0 <= y && y < H; }
	vector<Point> Adjacent4()const {
		vector<Point> v(4); rep(i, 4)v[i] = operator+(d[i]); return v;
	}
	vector<Point> Adjacent8()const {
		vector<Point> v(8); rep(i, 8)v[i] = operator+(d[i]); return v;
	}
	vector<Point> Adjacent4_inRange(int H, int W)const {
		vector<Point> ret;
		for (auto P : Adjacent4())if (P.inRange(H, W))ret.push_back(P);
		return ret;
	}
	vector<Point> Adjacent8_inRange(int H, int W)const {
		vector<Point> ret;
		for (auto P : Adjacent8())if (P.inRange(H, W))ret.push_back(P);
		return ret;
	}
};
bool operator<(Point p1, Point p2) { return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y); }
const vector<Point> Point::d{ {-1,0},{0,1},{1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1} };

// --- dump --- //
#if __has_include("dump.hpp")
#include "dump.hpp"
#else
#define dump(...) (void(0))
#endif


template<class T>class Combi {
	int Max; T Mod;
	vector<T> fac, finv, inv;
public:
	Combi(int _Max, T _Mod = 1000000007)
		: Max(_Max), Mod(_Mod)
		, fac(_Max), finv(_Max), inv(_Max) {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (int i = 2; i < Max; ++i) {
			fac[i] = fac[i - 1] * i % Mod;
			inv[i] = MOD - inv[Mod % i] * (Mod / i) % Mod;
			finv[i] = finv[i - 1] * inv[i] % Mod;
		}
	}
	T operator()(int n, int m) {
		return (n < m || n < 0 || m < 0) ? 0 : fac[n] * (finv[m] * finv[n - m] % Mod) % Mod;
	}
};

int main() {
	LL h = in, w = in, k = in;
	LL ans = 0;
	rep(i, h)rep(j, w) {
		LL sum = 0;
		if (i && j) {
			sum = 2 * LL(h - i) * LL(w - j);
		} else {
			sum = LL(h - i) * LL(w - j);
		}
		sum %= MOD;
		sum *= i + j; sum %= MOD;
		ans += sum; ans %= MOD;
	}

	Combi<LL> com(300009);
	ans *= com(h * w - 2, k - 2); ans %= MOD;
	out(ans);
}