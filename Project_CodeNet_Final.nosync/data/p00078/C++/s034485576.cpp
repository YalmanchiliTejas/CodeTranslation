#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define rrep(i, n) for(int i=(n)-1; i>=0; --i)
#define rfor(i, m, n) for(int i=(m); i>=(n); --i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;		using LL = long long;
using VB = vector<bool>;	using VVB = vector<VB>;
using VI = vector<int>;		using VVI = vector<VI>;
using VL = vector<LL>;		using VVL = vector<VL>;
using VS = vector<string>;	using VD = vector<double>;
using PII = pair<int, int>;	using VP = vector<PII>;
using PLL = pair<LL, LL>;	using VPL = vector<PLL>;
template<class T>using pq = priority_queue<T>;
template<class T>using pqs = priority_queue<T, vector<T>, greater<T>>;
const int inf = (int)1e9;
const LL inf_ll = (LL)1e18, MOD = 1000000007;
const double PI = acos(-1.0), EPS = 1e-12;

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
template<class T, class U>inline int Find(const T& a, const U& v)noexcept { auto pos = find(all(a), v); return pos == a.end() ? -1 : pos - a.begin(); }
template<class T, class U>inline U Sum(const T& a, const U& v)noexcept { return accumulate(all(a), v); }
template<class T, class U>inline int Lower(const T& a, const U& v)noexcept { return lower_bound(all(a), v) - a.begin(); }
template<class T, class U>inline int Upper(const T& a, const U& v)noexcept { return upper_bound(all(a), v) - a.begin(); }
template<class T, class P>inline void RemoveIf(T& a, P f)noexcept { a.erase(remove_if(all(a), f), a.end()); }
template<class T>inline T Age(T n, T m)noexcept { return (n + m - 1) / m; }
template<class T>inline T Age2(T n, T m)noexcept { return Age(n, m) * m; }
template<class T>inline T Tri(T n)noexcept { return (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1); }
template<class T = long long>inline T BIT(int b)noexcept { return T{ 1 } << b; }
template<class T>inline T Gcd(T n, T m)noexcept { return m ? Gcd(m, n % m) : n; }
template<class T>inline T Lcm(T n, T m)noexcept { return n / Gcd(n, m) * m; }
template<class T>inline T Pow(T a, T n)noexcept { T r = 1; while (n > 0) { if (n & 1)r *= a; a *= a; n /= 2; }return r; }
template<class T>inline T Powmod(T a, T n, T m = MOD)noexcept { T r = 1; while (n > 0) { if (n & 1)r = r * a % m, n--; else a = a * a % m, n /= 2; }return r; }
template<class T>inline bool chmax(T& a, const T& b)noexcept { if (a < b) { a = b; return true; } return false; }
template<class T>inline bool chmin(T& a, const T& b)noexcept { if (a > b) { a = b; return true; } return false; }
inline string operator*(string s, int n)noexcept { string ret; rep(i, n)ret += s; return ret; }

// --- input --- //
#if defined(_MSC_VER) || defined(ONLINE_JUDGE)
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
inline int gc()noexcept { return getchar_unlocked(); }
template<class T>inline void InputF(T& v)noexcept { cin >> v; }
inline void InputF(char& v)noexcept { while (isspace(v = gc())); }
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
	template<class T>operator T()noexcept { T v; InputF(v); return v; }
	int operator--(int) { int v; InputF(v); v--; return v; }
	InputV operator[](int n)noexcept { return InputV(n); }
	InputV operator[](pair<int, int> n)noexcept { return InputV(n); }
	template<class T, size_t W>array<vector<T>, W> get(int H) {
		array<vector<T>, W> ret;
		rep(i, H)rep(j, W) { T x = *this; ret[j].push_back(x); }
		return ret;
	}
}in;

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
	void operator()() { printf("%s", D.l); }
	template<class H>void operator()(H&& h) {
		p(h); if (isPrint)printf("%s", D.l); isPrint = true; B = Yes; D = spc;
	}
	template<class H, class...T>void operator()(H&& h, T&& ...t) {
		p(h); if (isPrint)printf("%s", D.d); isPrint = true; operator()(forward<T>(t)...);
	}
	template<class...T>void exit(T&& ...t) {
		operator()(forward<T>(t)...); std::exit(EXIT_SUCCESS);
	}
}out;

// --- dump --- //
#if __has_include("dump.hpp")
#include "dump.hpp"
#else
#define dump(...) (void(0))
#endif

// ---------------------------------------------------------------- //

struct Point {
	int x, y;
	static int H, W;
	static const vector<Point> d;
	static void setRange(int _H, int _W) { H = _H; W = _W; }
	static constexpr Point Zero()noexcept { return { 0,0 }; }
	static constexpr Point One()noexcept { return { 1,1 }; }
	constexpr Point()noexcept :x(0), y(0) {}
	constexpr Point(int _x, int _y)noexcept :x(_x), y(_y) {}
	Point(int n)noexcept :x(n% W), y(n / W) {}
	constexpr Point operator+()const noexcept { return *this; }
	constexpr Point operator-()const noexcept { return { -x,-y }; }
	constexpr Point operator+(const Point& p)const noexcept { return Point(*this) += p; }
	constexpr Point operator-(const Point& p)const noexcept { return Point(*this) -= p; }
	constexpr Point operator*(const Point& p)const noexcept { return Point(*this) *= p; }
	constexpr Point operator/(const Point& p)const noexcept { return Point(*this) /= p; }
	constexpr Point operator%(const Point& p)const noexcept { return Point(*this) %= p; }
	constexpr Point operator+(const int n)const noexcept { return Point(*this) += Point(n, n); }
	constexpr Point operator-(const int n)const noexcept { return Point(*this) -= Point(n, n); }
	constexpr Point operator*(const int n)const noexcept { return Point(*this) *= Point(n, n); }
	constexpr Point operator/(const int n)const noexcept { return Point(*this) /= Point(n, n); }
	constexpr Point operator%(const int n)const noexcept { return Point(*this) %= Point(n, n); }
	constexpr Point& operator+=(const Point& p)noexcept { x += p.x; y += p.y; return *this; }
	constexpr Point& operator-=(const Point& p)noexcept { x -= p.x; y -= p.y; return *this; }
	constexpr Point& operator*=(const Point& p)noexcept { x *= p.x; y *= p.y; return *this; }
	constexpr Point& operator/=(const Point& p)noexcept { x /= p.x; y /= p.y; return *this; }
	constexpr Point& operator%=(const Point& p)noexcept { x %= p.x; y %= p.y; return *this; }
	constexpr Point& operator+=(const int n)noexcept { x += n; x += n; return *this; }
	constexpr Point& operator-=(const int n)noexcept { x -= n; x -= n; return *this; }
	constexpr Point& operator*=(const int n)noexcept { x *= n; x *= n; return *this; }
	constexpr Point& operator/=(const int n)noexcept { x /= n; x /= n; return *this; }
	constexpr Point& operator%=(const int n)noexcept { x %= n; x %= n; return *this; }
	bool operator==(const Point& p)const noexcept { return to_i() == p.to_i(); }
	bool operator!=(const Point& p)const noexcept { return to_i() != p.to_i(); }
	bool operator<(const Point& p)const noexcept { return to_i() < p.to_i(); }
	bool operator<=(const Point& p)const noexcept { return to_i() <= p.to_i(); }
	bool operator>(const Point& p)const noexcept { return to_i() > p.to_i(); }
	bool operator>=(const Point& p)const noexcept { return to_i() >= p.to_i(); }
	constexpr int operator[](int i)const noexcept { return i == 0 ? x : i == 1 ? y : 0; }
	bool inRange()const noexcept { return 0 <= x && x < W && 0 <= y && y < H; }
	int to_i()const noexcept { return x + y * W; }
	int dist(const Point& p)const noexcept { return std::abs(x - p.x) + std::abs(y - p.y); }
	Point abs(const Point& p)const noexcept { return { std::abs(x - p.x),std::abs(y - p.y) }; }
	Point& swap()noexcept { std::swap(x, y); return *this; }
	constexpr int min()noexcept { return std::min(x, y); }
	constexpr int max()noexcept { return std::max(x, y); }
	vector<Point> adjacent4()const noexcept {
		vector<Point> v(4); for (int i = 0; i < 4; ++i)v[i] = *this + d[i]; return v;
	}
	vector<Point> adjacent8()const noexcept {
		vector<Point> v(8); for (int i = 0; i < 8; ++i)v[i] = *this + d[i]; return v;
	}
	vector<Point> adjacent4_inRange()const noexcept {
		vector<Point> v; for (const auto& P : adjacent4())if (P.inRange())v.push_back(P); return v;
	}
	vector<Point> adjacent8_inRange()const noexcept {
		vector<Point> v; for (const auto& P : adjacent8())if (P.inRange())v.push_back(P); return v;
	}
};
int Point::H, Point::W;
const vector<Point> Point::d{ {-1,0},{0,1},{1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1} };
ostream& operator<<(ostream& os, const Point& p)noexcept { return os << '(' << p.x << ',' << p.y << ')'; }
istream& operator>>(istream& is, Point& p)noexcept { return is >> p.y >> p.x; }

int main() {
	int n;
	while (cin >> n && n) {
		VVI ans(n, VI(n, -1));
		Point p(n / 2, n / 2 + 1);
		int num = 1;
		ans[p.y][p.x] = num++;
		while (num <= n * n) {
			p = (p + Point(1, 1)) % n;
			while (ans[p.y][p.x] != -1) {
				p = (p + Point(-1 + n, 1 + n)) % n;
			}
			ans[p.y][p.x] = num++;
		}
		rep(i, n)rep(j, n) {
			printf("%4d%s", ans[i][j], j == n - 1 ? "\n" : "");
		}
	}
}
