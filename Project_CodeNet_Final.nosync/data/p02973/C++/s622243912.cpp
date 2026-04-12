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
using VI=vector<int>;      using VL=vector<LL>;
using VS=vector<string>;   using VD=vector<double>;
using VVI=vector<VI>;      using VVL=vector<VL>;
using PII=pair<int, int>;  using PLL=pair<LL, LL>;
const int inf = (int)1e9;  const double pi = acos(-1.0);
const LL MOD = 1000000007; const string Snum = "0123456789";
const int dx[] = { -1,0,1,0,-1,-1,1,1 }, dy[] = { 0,1,0,-1,-1,1,-1,1 };
template<class T>void Sort(T& a) { sort(all(a)); }
template<class T>void ReSort(T& a) { sort(a.rbegin(), a.rend()); }
template<class T>void Reverse(T& a) { reverse(all(a)); }
template<class T>void Unique(T& a) { a.erase(unique(all(a)), a.end()); }
template<class T>auto Max(const T& a) { return *max_element(all(a)); }
template<class T>auto Min(const T& a) { return *min_element(all(a)); }
template<class T>int MaxPos(const T& a) { return max_element(all(a)) - a.begin(); }
template<class T>int MinPos(const T& a) { return min_element(all(a)) - a.begin(); }
template<class T, class U>int Count(const T& a, U v) { return count(all(a), v); }
template<class T, class U>U Sum(const T& a, U v) { return accumulate(all(a), v); }
template<class T, class U>int Lower(const T& a, U v) { return lower_bound(all(a), v) - a.begin(); }
template<class T, class U>int Upper(const T& a, U v) { return upper_bound(all(a), v) - a.begin(); }
template<class T, class P>void RemoveIf(T& a, P f) { a.erase(remove_if(all(a), f), a.end()); }
template<class T>T Age(T n, T m) { return (n + m - 1) / m; }
template<class T>T Gcd(T n, T m) { return m == 0 ? n : Gcd(m, n % m); }
template<class T>T Lcm(T n, T m) { return n / Gcd(n, m) * m; }
template<class T>T Pow(T a, T n) { T r = 1; while (n > 0) { if (n & 1)r *= a; a *= a; n /= 2; }return r; }
template<class T>T Powmod(T a, T n, T m = MOD) { T r = 1; while (n > 0) { if (n & 1)r = r * a % m, n--; else a = a * a % m, n /= 2; }return r; }

/* INPUT */
template<class T>T InputF() { T o; cin >> o; return o; }
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
string GetLine() {
	string ret; char c = getchar_unlocked();
	while (c != '\0' && c != '\n') { ret.push_back(c); c = getchar_unlocked(); }
	return ret;
}

template<class T>T StoT(string s) { return s; }
template<> char StoT(string s) { return s.front(); }
template<> string StoT(string s) { return s; }
template<> int StoT(string s) { return stoi(s); }
template<> LL StoT(string s) { return stoll(s); }
template<> double StoT(string s) { return stod(s); }

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
class ostreamfbuff : public basic_streambuf<char, char_traits<char>> {
protected:int overflow(int nCh = EOF) { putchar_unlocked(nCh); return 0; }
};
class ostreamf : public basic_iostream<char, char_traits<char>> {
public:ostreamf(void) : basic_iostream<char, char_traits<char>>(new ostreamfbuff()) {}
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
	int n = ini; VI a = ini[n];

	multiset<int> mt;
	for (auto i : a) {
		auto pos = mt.lower_bound(i);

		if (pos == mt.begin()) {
			mt.insert(i);
		}
		else if (pos == mt.end()) {
			pos--;
			mt.erase(pos);
			mt.insert(i);
		}
		else {
			pos--;
			mt.erase(pos);
			mt.insert(i);
		}
	}

	out, sz(mt), out;
}