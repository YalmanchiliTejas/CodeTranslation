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

using namespace std;
using LL=long long;
using VI=vector<int>;		using VL=vector<LL>;
using VS=vector<string>;	using VD=vector<double>;
using VVI=vector<VI>;		using VVL=vector<VL>;
using PII=pair<int, int>;	using PLL=pair<LL, LL>;
using VP=vector<PII>;		using VPL=vector<PLL>;
const int inf = (int)1e9;	const double PI = acos(-1.0);
const LL MOD = 1000000007;	const double EPS = 1e-10;
const int dx[] = { -1,0,1,0,-1,-1,1,1 }, dy[] = { 0,1,0,-1,-1,1,-1,1 };

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
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
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
	while ('0' <= c && c <= '9') { ret = ret * 10 + (c - '0'); c = getchar_unlocked(); }
	return neg ? -ret : ret;
}
template<> LL InputF() {
	LL ret = 0; bool neg = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while ('0' <= c && c <= '9') { ret = ret * 10LL + (LL(c) - LL('0')); c = getchar_unlocked(); }
	return neg ? -ret : ret;
}
template<> double InputF() {
	double ret = 0, dp = 1; bool neg = false, adp = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while (('0' <= c && c <= '9') || c == '.') {
		if (c == '.') {
			adp = true;
		} else if (adp) {
			dp *= 0.1; ret += (c - '0') * dp;
		} else {
			ret = ret * 10.0 + (c - '0');
		}
		c = getchar_unlocked();
	}
	return neg ? -ret : ret;
}
string GetLine() {
	string ret; char c = getchar_unlocked();
	while (c != '\0' && c != '\n') { ret.push_back(c); c = getchar_unlocked(); }
	return ret;
}
template<class T>T Parse(string s) { return s; }
template<> char Parse(string s) { return s.front(); }
template<> string Parse(string s) { return s; }
template<> int Parse(string s) { return stoi(s); }
template<> LL Parse(string s) { return stoll(s); }
template<> double Parse(string s) { return stod(s); }

VS InputB;
template<class T>struct InputC {
	operator T() { return InputF<T>(); }
	vector<T> operator[](int h) {
		vector<T> ret(h);
		rep(i, h)ret[i] = InputF<T>();
		return ret;
	}
	vector<vector<T>> operator[](PII p) {
		int h, w; tie(h, w) = p;
		vector<vector<T>> ret(h, vector<T>(w));
		rep(i, h)rep(j, w)ret[i][j] = InputF<T>();
		return ret;
	}
	T operator()(int n) {
		while (sz(InputB) <= n)InputB.pb(InputF<string>());
		return Parse<T>(InputB[n]);
	}
	vector<T> operator()(int n, int h) {
		vector<T> ret(h);
		rep(i, h)ret[i] = operator()(i + n);
		return ret;
	}
	vector<vector<T>> operator()(int n, int h, int w) {
		vector<vector<T>> ret(h, vector<T>(w));
		rep(i, h)rep(j, w)ret[i][j] = operator()(n + i * w + j);
		return ret;
	}
};
InputC<char> inc; InputC<string> ins; InputC<int> ini; InputC<LL> inl; InputC<double> ind;

// --- output --- //
struct BoolStr {
	const char* t, * f;
	BoolStr(const char* _t, const char* _f) :t(_t), f(_f) {}
}Yes("Yes", "No"), yes("yes", "no"), YES("YES", "NO");
struct DivStr {
	const char* d, * l;
	DivStr(const char* _d, const char* _l) :d(_d), l(_l) {}
}spc(" ", "\n"), no_spc("", "\n"), comma(",", "\n"), no_endl(" ", "");
class Print {
	BoolStr B{ Yes }; DivStr D{ spc };
	void p(int v) { printf("%d", v); }
	void p(long long v) { printf("%lld", v); }
	void p(double v) { printf("%.20f", v); }
	void p(bool v) { printf(v ? B.t : B.f); }
	template<class T>void p(const T& v) { cout << v; }
	template<class T, class U>void p(const pair<T, U>& v) {
		p(v.first); printf(D.d); p(v.second);
	}
	template<class T>void p(const vector<T>& v) {
		for (int i = 0, s = v.size(); i < s; ++i) { if (i)printf(D.d); p(v[i]); }
	}
	template<class T>void p(const vector<vector<T>>& v) {
		for (int i = 0, s = v.size(); i < s; ++i) { if (i)printf(D.l); p(v[i]); }
	}
	void p(const BoolStr& v) { B = v; }
	void p(const DivStr& v) { D = v; }
	template<class T>bool isPrint(const T& v) {
		return !is_same<BoolStr, T>::value && !is_same<DivStr, T>::value;
	}
public:
	template<class H>void operator()(H&& h) {
		p(h); if (isPrint(h))printf(D.l); B = Yes; D = spc;
	}
	template<class H, class...T>void operator()(H&& h, T&& ...t) {
		p(h); if (isPrint(h))printf(D.d); operator()(forward<T>(t)...);
	}
}out;

// --- answer --- //
template<class T>struct Answer {
	T min, max, sum; int cnt;
	Answer() :min(numeric_limits<T>::max()), max(numeric_limits<T>::min()), sum(0), cnt(0) {}
	void operator=(T n) { min = std::min(min, n); max = std::max(max, n); sum += n; cnt++; }
	operator bool() { return cnt; }
};

// --- step --- //
class step {
	struct It {
		int x, s;
		It(int _x, int _s) :x(_x), s(_s) { assert(s); }
		int operator*() { return x; }
		bool operator!=(It& i) { return 0 < s ? x < i.x : x >= i.x; }
		void operator++() { x += s; }
	};
	int x, y, s;
public:
	step(int _y, int _s = 1) :x(0 < _s ? 0 : _y), y(0 < _s ? _y : 0), s(_s) {}
	step(int _x, int _y, int _s) :x(_x), y(_y), s(_s) {}
	It begin() { return { x,s }; }
	It end() { return { y,s }; }
};

// --- dump --- //
// #define LOCAL
#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...) (void(0))
#endif // LOCAL

VL cnt, pa;

LL dfs(int L, LL X) {
	if (L == 0) {
		return 1;
	} else if (X <= 1) {
		return 0;
	} else if (X <= 1 + cnt[L - 1]) {
		return dfs(L - 1, X - 1);
	} else if (X <= 2 + cnt[L - 1]) {
		return pa[L - 1] + 1;
	} else if (X <= 2 + cnt[L - 1] * 2) {
		return pa[L - 1] + 1 + dfs(L - 1, X - 2 - cnt[L - 1]);
	} else {
		return pa[L];
	}
};

int main() {
	int n = ini; LL x = inl;
	cnt.resize(n + 1); pa.resize(n + 1);
	cnt[0] = 1; pa[0] = 1;
	FOR(i, 1, n + 1) {
		cnt[i] = cnt[i - 1] * 2 + 3;
		pa[i] = pa[i - 1] * 2 + 1;
	}
	out(dfs(n, x));
}

/*

[L] = (B)[L-1](P)[L-1](B)

*/