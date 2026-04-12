#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define repi(n) for(int i=0; i<(n); ++i)
#define repj(n) for(int j=0; j<(n); ++j)
#define repk(n) for(int k=0; k<(n); ++k)
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
struct SORT {}SOrt;
template<class T> T operator |(T v, SORT s) {
	return Sort(v);
}
char Snum[] = "0123456789";


/* MOD */
LL modpow(LL a, LL n, LL _MOD = MOD) {
	LL re = 1;
	while (n > 0) {
		if (n & 1)re = re * a % _MOD;
		a = a * a % _MOD; n >>= 1;
	}
	return re;
}
LL modinv(LL n, LL _MOD = MOD) {
	return modpow(n, _MOD - 2, _MOD);
}
struct Modl {
	LL val = 0;
	Modl(LL v = 0)noexcept :val(v% MOD) { if (val < 0)v += MOD; }
	operator LL() { return val; }
};
Modl operator-(const Modl & a) { Modl r; r.val = a.val ? MOD - a.val : 0; return r; }
Modl operator+(const Modl & a, const Modl & b) { Modl r(a.val + b.val); return r; }
Modl operator-(const Modl & a, const Modl & b) { Modl r(a.val - b.val); return r; }
Modl operator*(const Modl & a, const Modl & b) { Modl r(a.val * b.val); return r; }
Modl operator/(const Modl & a, const Modl & b) { Modl r(a.val * modinv(b.val, MOD)); return r; }

Modl operator+(const Modl & a, const int& b) { Modl r(a.val + LL(b)); return r; }
Modl operator-(const Modl & a, const int& b) { Modl r(a.val - LL(b)); return r; }
Modl operator*(const Modl & a, const int& b) { Modl r(a.val * LL(b)); return r; }
Modl operator/(const Modl & a, const int& b) { Modl r(a.val * modinv(LL(b), MOD)); return r; }

Modl operator+(const Modl & a, const LL & b) { Modl r(a.val + b); return r; }
Modl operator-(const Modl & a, const LL & b) { Modl r(a.val - b); return r; }
Modl operator*(const Modl & a, const LL & b) { Modl r(a.val * b); return r; }
Modl operator/(const Modl & a, const LL & b) { Modl r(a.val * modinv(b, MOD)); return r; }

Modl operator+(const int& a, const Modl & b) { Modl r(LL(a) + b.val); return r; }
Modl operator-(const int& a, const Modl & b) { Modl r(LL(a) - b.val); return r; }
Modl operator*(const int& a, const Modl & b) { Modl r(LL(a) * b.val); return r; }
Modl operator/(const int& a, const Modl & b) { Modl r(LL(a) * modinv(b.val, MOD)); return r; }

Modl operator+(const LL & a, const Modl & b) { Modl r(a + b.val); return r; }
Modl operator-(const LL & a, const Modl & b) { Modl r(a - b.val); return r; }
Modl operator*(const LL & a, const Modl & b) { Modl r(a * b.val); return r; }
Modl operator/(const LL & a, const Modl & b) { Modl r(a * modinv(b.val, MOD)); return r; }
Modl pow(Modl a, int n) { Modl r(modpow(a, n)); return r; }
Modl pow(Modl a, LL n) { Modl r(modpow(a, n)); return r; }

/* RANGE */
namespace RangeNS {
	template<typename T>class Range {
		const T start_, stop_, step_;
	public:
		Range(const T& start, const T& stop, const T& step) : start_{ start }, stop_{ stop }, step_{ step } {assert(!(step_ == 0 || (start_ > stop_ && step_ > 0) || (start_ < stop_ && step_ < 0))); }
		class iterator {
			T value_; const T start_, stop_, step_;
		public:
			iterator(T value, T step, T start, T stop) : value_{ value }, step_{ step }, start_{ start }, stop_{ stop } {}
			iterator operator++() { value_ = std::min(std::max(start_, stop_), std::max(std::min(start_, stop_), value_ + step_)); return *this; }
			T & operator*() { return value_; }
			const T* operator->() { return &value_; }
			bool operator==(const iterator & rhs) { return value_ == rhs.value_; }
			bool operator!=(const iterator & rhs) { return value_ != rhs.value_; }
		};
		iterator begin() const { return iterator(start_, step_, start_, stop_); }
		iterator end() const { return iterator(stop_, step_, start_, stop_); }
		explicit operator vector<T>() const { vector<T>t; for (T i = start_; i < stop_; i += step_)t.push_back(i); return t; }
	};
	template <typename T, typename Func, typename FuncType> class Range2 {
		using Itr = typename T::iterator; Itr begin_, end_; Func f_;
	public:
		Range2(T& v, Func f) : begin_{ v.begin() }, end_{ v.end() }, f_{ f } {}
		class iterator {
		public:
			//typedef std::forward_iterator_tag iterator_category;
			iterator(Itr itr, Func f) : itr_{ itr }, f_{ f } {}
			iterator operator++() { ++itr_; return *this; }
			FuncType operator*() { return f_(*itr_); }
			bool operator==(iterator rhs) { return rhs.itr_ == itr_; }
			bool operator!=(iterator rhs) { return rhs.itr_ != itr_; }
		private:
			Itr itr_; Func f_;
		};
		iterator begin() const { return iterator(begin_, f_); }
		iterator end() const { return iterator(end_, f_); }
		operator vector<FuncType>() const { vector<FuncType>t; for (Itr i = begin_; i != end_; ++i)t.push_back(f_(*i)); return t; }
	};
}
template<typename T> RangeNS::Range<T> range(const T & stop) { return RangeNS::Range<T>(T{ 0 }, stop, T{ 1 }); }
template<typename T> RangeNS::Range<T> range(const T & start, const T & stop) { return RangeNS::Range<T>(start, stop, T{ 1 }); }
template<typename T> RangeNS::Range<T> range(const T & start, const T & stop, const T & step) { return RangeNS::Range<T>(start, stop, step); }
template<typename _T> ostream& operator << (ostream & ostr, const vector<_T> & v) {
	if (v.size() == 0) { ostr << ""; return ostr; }ostr << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++)ostr << " " << *itr; return ostr;
}
template<typename T> ostream& operator << (ostream & ostr, const RangeNS::Range<T> & r) { ostr << vector<T>(r); return ostr; }
template<typename T, typename Func, typename FuncType> ostream& operator << (ostream & ostr, const RangeNS::Range2<T, Func, FuncType> & r) { ostr << vector<FuncType>(r); return ostr; }
template<class T, class Func> auto operator | (T & v, Func f) { RangeNS::Range2<T, Func, decltype(f(*v.begin()))>r(v, f); return r; }
template<class T, class Func> auto operator | (T && v, Func f) { RangeNS::Range2<T, Func, decltype(f(*v.begin()))>r(v, f); return r; }

/* INPUT */
struct inputter_Str {
	vector<string> inputbuffer;
	string operator [](int n) { while (inputbuffer.size() <= n) { string s; cin >> s; inputbuffer.push_back(s); }return inputbuffer[n]; }
	operator string() { return this[inputbuffer.size()]; }
}; inputter_Str in;
struct inputter_Int {
	int operator [](int n) { return stoi(in[n]); }
	operator int() { return stoi(string(in)); }
}; inputter_Int ini;
struct inputter_LL {
	LL operator [](int n) { return stoll(in[n]); }
	operator int() { return stoll(string(in)); }
}; inputter_LL inl;
struct inputter_Double {
	double operator [](int n) { return stod(in[n]); }
	operator int() { return stold(string(in)); }
}; inputter_Double ind;
VI invi(int n, int m) { VI v(m); for (int i = 0; i < m; ++i)v[i] = ini[n + i]; return v; }
VL invl(int n, int m) { VL v(m); for (int i = 0; i < m; ++i)v[i] = inl[n + i]; return v; }
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

int re(int n, int f, int k) {
	return (f + k > n) ? f + k - n : f + k;
}

int main() {
	int n = ini[0], Q = ini[1];
	int first = 1;
	rep(i, Q) {
		int q; cin >> q;
		if (q == 0) {
			int k; cin >> k;
			out, re(n, first, k - 1), out;
		}
		else {
			int k; cin >> k;
			first = re(n, first, k);
		}
	}
}
