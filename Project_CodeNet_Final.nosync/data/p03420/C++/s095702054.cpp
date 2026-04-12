#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#if defined(_MSC_VER) || defined(ONLINE_JUDGE)
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << endl;
using LL=long long;
using VS=vector<string>;   using VD=vector<double>;
using VI=vector<int>;      using VL=vector<LL>;
using VVI=vector<VI>;      using VVL=vector<VL>;
using PII=pair<int, int>;  using PLL=pair<LL, LL>;
const int inf = (int)1e9;  const double pi = acos(-1.0);
const LL MOD = 1000000007; const string Snum = "0123456789";
const int dx[] = { -1,0,1,0,-1,-1,1,1 }, dy[] = { 0,1,0,-1,-1,1,-1,1 };
template<class T>void Sort(T& a) { sort(a.begin(), a.end()); }
template<class T>void ReSort(T& a) { sort(a.rbegin(), a.rend()); }
template<class T>void Reverse(T& a) { reverse(a.begin(), a.end()); }
template<class T>void Unique(T& a) { a.erase(unique(a.begin(), a.end()), a.end()); }
template<class T>auto Max(const T& a) { return *max_element(a.begin(), a.end()); }
template<class T>auto Min(const T& a) { return *min_element(a.begin(), a.end()); }
template<class T, class U>int Count(const T& a, U c) { return count(a.begin(), a.end(), c); }
template<class T, class U>U Sum(const T& a, U init = 0) { return accumulate(a.begin(), a.end(), init); }
template<class T, class U>int Lower(const T& a, U s) { return lower_bound(a.begin(), a.end(), s) - a.begin(); }
template<class T, class U>int Upper(const T& a, U s) { return upper_bound(a.begin(), a.end(), s) - a.begin(); }
template<class T>T Age(T a, T b) { return (a + b - 1) / b; }
template<class T>T Gcd(T n, T m) { return m == 0 ? n : Gcd(m, n % m); }
template<class T>T Lcm(T n, T m) { return n / Gcd(n, m) * m; }

/* INPUT */
template<class T>T InputF() { return 0; }
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
		if (c == '.') { adp = true; }
		else if (adp) { dp *= 0.1; ret += (c - '0') * dp; }
		else { ret = ret * 10.0 + (c - '0'); }
		c = getchar_unlocked();
	}
	return neg ? -ret : ret;
}

template<class T>T StoT(string s) { return s; }
template<> char StoT(string s) { return s.front(); }
template<> string StoT(string s) { return s; }
template<> int StoT(string s) { return stoi(s); }
template<> LL StoT(string s) { return stoll(s); }
template<> double StoT(string s) { return stod(s); }

string GetLine() {
	string ret; char c = getchar_unlocked();
	while (c != '\0' && c != '\n') { ret.push_back(c); c = getchar_unlocked(); }
	return ret;
}

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
	T at(int n) {
		while (sz(InputB) <= n)InputB.pb(InputF<string>());
		return StoT<T>(InputB[n]);
	}
	vector<T> at(int n, int h) {
		vector<T> ret(h);
		rep(i, h)ret[i] = at(i + n);
		return ret;
	}
	vector<vector<T>> at(int n, int h, int w) {
		vector<vector<T>> ret(h, vector<T>(w));
		rep(i, h)rep(j, w)ret[i][j] = at(n + i * w + j);
		return ret;
	}
};
InputC<char> inc; InputC<string> ins; InputC<int> ini; InputC<LL> inl; InputC<double> ind;

/* OUTPUT */
class ostreamfbuff : public std::basic_streambuf<char, std::char_traits<char>> {
protected:int overflow(int nCh = EOF) { putchar_unlocked(nCh); return 0; }
};
class ostreamf : public std::basic_iostream<char, std::char_traits<char>> {
public:ostreamf(void) : std::basic_iostream<char, std::char_traits<char>>(new ostreamfbuff()) {}
};
ostreamf coutf; ostream& operator<<(ostream& ostr, InputC<string> i) { ostr << string(i); return ostr; }
struct BoolStr { string t, f; BoolStr(string tr, string fa) :t(tr), f(fa) {} }yes("yes", "no"), Yes("Yes", "No"), YES("YES", "NO"), Yay("Yay!", ":(");
struct Divizer { string s; Divizer(string s_) :s(s_) {} }spc(" "), nosp(""), comma(","), lin("\n");
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
	template<class T, class U>void print(const map<T, U>& o) {
		coutf << "Map"; for (auto a : o) { coutf << " {"; print(a); coutf << "},"; } coutf << "\n";
	}
	template<class T>void print(const set<T>& o) {
		coutf << "Set {"; for (auto a : o) { print(a); coutf << ","; } coutf << "}\n";
	}
	template<class T>Output operator ,(T o) {
		if (flag)coutf << di.s; print(o);
		Output t(true, bs, di); return t;
	}
	Output operator,(Output o) { coutf << '\n'; return o; }
	Output operator,(BoolStr b) { Output t(flag, b, di); return t; }
	Output operator,(Divizer d) { Output t(flag, bs, d); return t; }
}out(false, Yes, spc);

/* ANSWER */
struct Answer {
	int mini = INT_MAX, maxi = INT_MIN, sumi = 0;
	LL minl = LLONG_MAX, maxl = LLONG_MIN, suml = 0;
	double mind = DBL_MAX, maxd = DBL_MIN, sumd = 0; int cnt = 0;
	void operator=(int n) { mini = min(mini, n); maxi = max(maxi, n); sumi += n; cnt++; }
	void operator=(LL n) { minl = min(minl, n); maxl = max(maxl, n); suml += n; cnt++; }
	void operator=(double n) { mind = min(mind, n); maxd = max(maxd, n); sumd += n; cnt++; }
}ans;


int main() {
	int n = ini, k = ini;
	LL Ans = 0;
	FOR(b, 1, n + 1) {
		LL cnt = (n / b) * max(0, b - k) + max(0, (n % b) - k + 1);
		Ans += cnt;
	}
	out, Ans - n * (!k), out;
}