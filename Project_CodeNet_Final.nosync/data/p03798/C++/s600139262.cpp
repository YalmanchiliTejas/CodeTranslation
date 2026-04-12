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
		rep(i, h)ret[i] = InputC::operator()(i + n);
		return ret;
	}
	vector<vector<T>> operator()(int n, int h, int w) {
		vector<vector<T>> ret(h, vector<T>(w));
		rep(i, h)rep(j, w)ret[i][j] = InputC::operator()(n + i * w + j);
		return ret;
	}
};
InputC<char> inc; InputC<string> ins; InputC<int> ini; InputC<LL> inl; InputC<double> ind;

// --- output --- //
class ostreamfbuff : public basic_streambuf<char, char_traits<char>> {
protected:int overflow(int nCh = EOF) { putchar_unlocked(nCh); return 0; }
};
class ostreamf : public basic_iostream<char, char_traits<char>> {
public:ostreamf(void) : basic_iostream<char, char_traits<char>>(new ostreamfbuff()) {}
}coutf;
struct BoolStr { string t, f; BoolStr(string _t, string _f) :t(_t), f(_f) {} }yes("yes", "no"), Yes("Yes", "No"), YES("YES", "NO"), Yay("Yay!", ":(");
struct Divizer { string s; Divizer(string _s) :s(_s) {} }spc(" "), nosp(""), comma(","), lin("\n");
struct Output {
	bool flag = false; BoolStr bs; Divizer di;
	Output(bool f, BoolStr b, Divizer d) :flag(f), bs(b), di(d) {}
	template<class T>void print(T o) { coutf << o; }
	void print(double o) { printf("%.20f", o); }
	void print(bool o) { coutf << (o ? bs.t : bs.f); }
	template<class T, class U>void print(const pair<T, U>& o) {
		print(o.first); coutf << di.s; print(o.second);
	}
	template<class T>void print(const vector<T>& o) {
		for (int i = 0; i < (int)o.size(); ++i) { if (i != 0)coutf << di.s; print(o[i]); }
	}
	template<class T>void print(const vector<vector<T>>& o) {
		for (int i = 0; i < (int)o.size(); ++i) { if (i != 0)coutf << '\n'; print(o[i]); }
	}
	template<class T>Output operator ,(T o) {
		if (flag)coutf << di.s; print(o); Output t(true, bs, di); return t;
	}
	Output operator,(Output o) { coutf << '\n'; Output t(false, bs, di); return t; }
	Output operator,(BoolStr b) { Output t(flag, b, di); return t; }
	Output operator,(Divizer d) { Output t(flag, bs, d); return t; }
}out(false, Yes, spc);


// --- answer --- //
template<class T>struct Answer {
	T min, max, sum; int cnt;
	Answer() :min(numeric_limits<T>::max()), max(numeric_limits<T>::min()), sum(0), cnt(0) {}
	void operator=(T n) { min = std::min(min, n); max = std::max(max, n); sum += n; cnt++; }
	operator bool() { return cnt; }
};

// --- dump --- //
// #define LOCAL
#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...) (void(0))
#endif // LOCAL


int main() {
	int n = ini;
	string s = ins;

	auto Re = [](char c) {return c == 'S' ? 'W' : 'S'; };

	auto Fit = [=](char c1, char c2, char s1) {
		if (c2 == 'S') {
			if (s1 == 'o')return c1;
			else return Re(c1);
		} else {
			if (s1 == 'o')return Re(c1);
			else return c1;
		}
	};

	auto MakeStr = [=](char c1, char c2) {
		string ret;
		ret += c1; ret += c2;
		FOR(i, 2, n) {
			ret += Fit(ret[i - 2], ret[i - 1], s[i - 1]);
		}
		return ret;
	};

	auto Check = [=](const string& str) {
		bool f1 = str.back() == Fit(str[1], str[0], s[0]);
		bool f2 = str.front() == Fit(str[n - 2], str[n - 1], s[n - 1]);
		return f1 && f2;
	};

	string s1 = MakeStr('S', 'S');
	string s2 = MakeStr('S', 'W');
	string s3 = MakeStr('W', 'S');
	string s4 = MakeStr('W', 'W');

	if (Check(s1)) {
		out, s1, out;
	} else if (Check(s2)) {
		out, s2, out;
	} else if (Check(s3)) {
		out, s3, out;
	} else if (Check(s4)) {
		out, s4, out;
	} else {
		out, -1, out;
	}
}