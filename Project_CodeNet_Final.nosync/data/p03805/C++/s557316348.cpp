#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << endl;
#define qp(f) [](auto i){return f;}
using LL=long long;
using VI=vector<int>;
using VL=vector<LL>;
using VS=vector<string>;
using VVI=vector<vector<int>>;
using PII=pair<int, int>;
const int inf = (int)1e9;
const LL MOD = 1000000007;
const double pi = acos(-1.0);
const string Snum = "0123456789";
const int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
template<class T>T Sort(T & a) { sort(a.begin(), a.end()); return a; }
template<class T>T ReSort(T& a) { sort(a.rbegin(), a.rend()); return a; }
template<class T>T Reverse(T& a) { reverse(a.begin(), a.end()); return a; }
template<class T>void Unique(T& a) { a.erase(unique(a.begin(), a.end()), a.end()); }
template<class T>auto Max(T a) { return *max_element(a.begin(), a.end()); }
template<class T>auto Min(T a) { return *min_element(a.begin(), a.end()); }
template<class T, class U>int Count(T a, U c) { return count(a.begin(), a.end(), c); }
template<class T, class U>U Sum(T a, U init = 0) { return accumulate(a.begin(), a.end(), init); }
template<class T>T Age(T a, T b) { return (a + b - 1) / b; }
template<class T>T gcd(T n, T m) { return m == 0 ? n : gcd(m, n % m); }
template<class T>T lcm(T n, T m) { return n / gcd(n, m) * m; }

/* INPUT */
struct inputter_Str {
	vector<string> inputbuffer;
	string operator [](int n) { while (inputbuffer.size() <= n) { string s; cin >> s; inputbuffer.push_back(s); }return inputbuffer[n]; }
	operator string() { string s; cin >> s; inputbuffer.push_back(s); return s; }
}in;
struct inputter_Int {
	int operator [](int n) { return stoi(in[n]); }
	operator int() { return stoi(string(in)); }
}ini;
struct inputter_LL {
	LL operator [](int n) { return stoll(in[n]); }
	operator LL() { return stoll(string(in)); }
}inl;
struct inputter_Double {
	double operator [](int n) { return stod(in[n]); }
	operator double() { return stold(string(in)); }
}ind;
VI invi(int n, int m) { VI v(m); for (int i = 0; i < m; ++i)v[i] = ini[n + i]; return v; }
VL invl(int n, int m) { VL v(m); for (int i = 0; i < m; ++i)v[i] = inl[n + i]; return v; }
VS invs(int n, int m) { VS v(m); for (int i = 0; i < m; ++i)v[i] = in[n + i]; return v; }
int Suminvi(int n, int m) { return Sum(invi(n, m), 0); }LL Suminvl(int n, int m) { return Sum(invl(n, m), 0LL); }
int Maxinvi(int n, int m) { return  Max(invi(n, m)); }LL Maxinvl(int n, int m) { return Max(invl(n, m)); }
int Mininvi(int n, int m) { return  Min(invi(n, m)); }LL Mininvl(int n, int m) { return Min(invl(n, m)); }

/* OUTPUT */
struct boolswitch { string t, f; boolswitch(string tr, string fa) :t(tr), f(fa) {} }yes("yes", "no"), Yes("Yes", "No"), YES("YES", "NO"), Yay("Yay!", ":(");
struct divizer { string s; divizer(string s_) :s(s_) {} }spc(" "), nosp("");
struct outputter {
	bool flag = false; boolswitch bs; divizer di;
	outputter(bool f, boolswitch b, divizer d) :flag(f), bs(b), di(d) {}
	template<class T>outputter operator ,(T o) {
		if (flag)cout << di.s; cout << o;
		outputter t(true, bs, di); return t;
	}
	outputter operator ,(double o) {
		if (flag)cout << di.s; printf("%.20f", o);
		outputter t(true, bs, di); return t;
	}
	outputter operator ,(bool o) {
		if (flag)cout << di.s; cout << (o ? bs.t : bs.f);
		outputter t(true, bs, di); return t;
	}
	template<class T> outputter operator ,(vector<T> o) {
		if (flag)cout << di.s;
		for (int i = 0; i < (int)o.size(); ++i)cout << o[i] << (i == (int)o.size() - 1 ? "" : di.s);
		outputter t(true, bs, di); return t;
	}
	template<class T, class U> outputter operator ,(pair<T, U> o) {
		if (flag)cout << di.s;
		cout << "[" << o.first, ", " << o.second << "]";
		outputter t(true, bs, di); return t;
	}
	outputter operator ,(outputter o) { cout << '\n'; return o; }
	outputter operator ,(boolswitch b) { outputter t(flag, b, di); return t; }
	outputter operator ,(divizer d) { outputter t(flag, bs, d); return t; }
}out(false, Yes, spc);

/* ANSWER */
struct Answer {
	int mini = INT_MAX, maxi = INT_MIN, sumi = 0;
	LL minl = LLONG_MAX, maxl = LLONG_MIN, suml = 0LL;
	double mind = DBL_MAX, maxd = DBL_MIN, sumd = 0.;
	int count = 0;
	void operator =(int n) { mini = min(mini, n); maxi = max(maxi, n); sumi += n; count++; }
	void operator =(LL n) { minl = min(minl, n); maxl = max(maxl, n); suml += n; count++; }
	void operator =(double n) { mind = min(mind, n); maxd = max(maxd, n); sumd += n; count++; }
}ans;


int main() {
	int n = ini[0], m = ini[1];
	vector<vector<bool>> d(n, vector<bool>(n));
	rep(i, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		d[a][b] = d[b][a] = true;
	}

	VI e(n - 1); rep(i, n - 1)e[i] = i + 1;
	do {
		bool flag = d[0][e[0]];
		rep(i, n - 2)if (!d[e[i]][e[i + 1]])flag = false;
		ans = flag;
	} while (next_permutation(all(e)));
	out, ans.sumi, out;
}