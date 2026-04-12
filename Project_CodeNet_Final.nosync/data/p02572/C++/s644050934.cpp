#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
#define incII(i, l, r) for(LL i = (l)    ; i <= (r); i++)
#define incID(i, l, r) for(LL i = (l)    ; i <  (r); i++)
#define incCI(i, l, r) for(LL i = (l) + 1; i <= (r); i++)
#define incCD(i, l, r) for(LL i = (l) + 1; i <  (r); i++)
#define decII(i, l, r) for(LL i = (r)    ; i >= (l); i--)
#define decID(i, l, r) for(LL i = (r) - 1; i >= (l); i--)
#define decCI(i, l, r) for(LL i = (r)    ; i >  (l); i--)
#define decCD(i, l, r) for(LL i = (r) - 1; i >  (l); i--)
#define inc(i, n)  incID(i, 0, n)
#define dec(i, n)  decID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define dec1(i, n) decII(i, 1, n)
auto inII = [](auto v, auto l, auto r) { return (l <= v && v <= r); };
auto inID = [](auto v, auto l, auto r) { return (l <= v && v <  r); };
auto inCI = [](auto v, auto l, auto r) { return (l <  v && v <= r); };
auto inCD = [](auto v, auto l, auto r) { return (l <  v && v <  r); };
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second
#define FR front()
#define BA back()
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
auto setmin   = [](auto & a, auto b) { return (b <  a ? a = b, true : false); };
auto setmax   = [](auto & a, auto b) { return (b >  a ? a = b, true : false); };
auto setmineq = [](auto & a, auto b) { return (b <= a ? a = b, true : false); };
auto setmaxeq = [](auto & a, auto b) { return (b >= a ? a = b, true : false); };
#define SC static_cast
#define SI(v) SC<int>(v.size())
#define SL(v) SC<LL >(v.size())
#define RF(e, v) for(auto & e: v)
#define until(e) while(! (e))
#define if_not(e) if(! (e))
#define ef else if
#define UR assert(false)
#define CT continue
#define RV(v) reverse(ALL(v))
auto * IS = & cin;
// input elements (as a tuple)
template<typename U, int I> void in_([[maybe_unused]] U & t) { }
template<typename U, int I, typename A, typename ... B> void in_(U & t) { (* IS) >> get<I>(t); in_<U, I + 1, B ...>(t); }
template<typename ... T> auto in() { tuple<T ...> t; in_<tuple<T ...>, 0, T ...>(t); return t; }
// input an array
template<typename T, int N> auto ain() { array<T, N> a; inc(i, N) { (* IS) >> a[i]; } return a; }
// input a (multi-dimensional) vector
template<typename T> T vin() { T v; (* IS) >> v; return v; }
template<typename T, typename N, typename ... M> auto vin(N n, M ... m) {
	vector<decltype(vin<T, M ...>(m ...))> v(n); inc(i, n) { v[i] = vin<T, M ...>(m ...); } return v;
}
// input multi-column (as a tuple of vector)
template<typename U, int I> void colin_([[maybe_unused]] U & t) { }
template<typename U, int I, typename A, typename ... B> void colin_(U & t) {
	A a; (* IS) >> a; get<I>(t).push_back(a); colin_<U, I + 1, B ...>(t);
}
template<typename ... T> auto colin(int n) {
	tuple<vector<T> ...> t; inc(i, n) { colin_<tuple<vector<T> ...>, 0, T ...>(t); } return t;
}
auto * OS = & cout;
// output elements
void out_([[maybe_unused]] string s) { }
template<typename A> void out_([[maybe_unused]] string s, A && a) { (* OS) << a; }
template<typename A, typename ... B> void out_(string s, A && a, B && ... b) { (* OS) << a << s; out_(s, b ...); }
auto outF = [](auto x, auto y, auto z, auto ... a) { (* OS) << x; out_(y, a ...); (* OS) << z << flush; };
auto out  = [](auto ... a) { outF("", " " , "\n", a ...); };
auto outS = [](auto ... a) { outF("", " " , " " , a ...); };
auto outL = [](auto ... a) { outF("", "\n", "\n", a ...); };
auto outN = [](auto ... a) { outF("", ""  , ""  , a ...); };
array<string, 3> SEQ_FMT = { "", " ", "" };
auto & SEQ_BEG = SEQ_FMT[0];
auto & SEQ_MID = SEQ_FMT[1];
auto & SEQ_END = SEQ_FMT[2];
// output a (multi-dimensional) vector
template<typename T> ostream & operator<<(ostream & os, vector<T> const & v) {
	os << SEQ_BEG; inc(i, SI(v)) { os << (i == 0 ? "" : SEQ_MID) << v[i]; } return (os << SEQ_END);
}
template<typename T> void vout_(T && v) { (* OS) << v; }
template<typename T, typename A, typename ... B> void vout_(T && v, A a, B ... b) {
	inc(i, SI(v)) { (* OS) << (i == 0 ? "" : a); vout_(v[i], b ...); }
}
template<typename T, typename A, typename ... B> void vout(T && v, A a, B ... b) {
	vout_(v, b ...); (* OS) << a << flush;
}

// ---- ----

template<LL M> class ModInt {
private:
	LL v;
	pair<LL, LL> ext_gcd(LL a, LL b) {
		if(b == 0) { assert(a == 1); return { 1, 0 }; }
		auto p = ext_gcd(b, a % b);
		return { p.SE, p.FI - (a / b) * p.SE };
	}
public:
	ModInt(LL vv = 0) { v = vv; if(abs(v) >= M) { v %= M; } if(v < 0) { v += M; } }
	LL get_v() { return v; }
	ModInt inv() { return ext_gcd(M, v).SE; }
	ModInt exp(LL b) {
		ModInt p = 1, a = v; if(b < 0) { a = a.inv(); b = -b; }
		while(b) { if(b & 1) { p *= a; } a *= a; b >>= 1; }
		return p;
	}
	friend bool      operator< (ModInt    a, ModInt   b) { return (a.v <  b.v); }
	friend bool      operator> (ModInt    a, ModInt   b) { return (a.v >  b.v); }
	friend bool      operator<=(ModInt    a, ModInt   b) { return (a.v <= b.v); }
	friend bool      operator>=(ModInt    a, ModInt   b) { return (a.v >= b.v); }
	friend bool      operator==(ModInt    a, ModInt   b) { return (a.v == b.v); }
	friend bool      operator!=(ModInt    a, ModInt   b) { return (a.v != b.v); }
	friend ModInt    operator+ (ModInt    a            ) { return ModInt(+a.v); }
	friend ModInt    operator- (ModInt    a            ) { return ModInt(-a.v); }
	friend ModInt    operator+ (ModInt    a, ModInt   b) { return ModInt(a.v + b.v); }
	friend ModInt    operator- (ModInt    a, ModInt   b) { return ModInt(a.v - b.v); }
	friend ModInt    operator* (ModInt    a, ModInt   b) { return ModInt(a.v * b.v); }
	friend ModInt    operator/ (ModInt    a, ModInt   b) { return a * b.inv(); }
	friend ModInt    operator^ (ModInt    a, LL       b) { return a.exp(b); }
	friend ModInt  & operator+=(ModInt  & a, ModInt   b) { return (a = a + b); }
	friend ModInt  & operator-=(ModInt  & a, ModInt   b) { return (a = a - b); }
	friend ModInt  & operator*=(ModInt  & a, ModInt   b) { return (a = a * b); }
	friend ModInt  & operator/=(ModInt  & a, ModInt   b) { return (a = a / b); }
	friend ModInt  & operator^=(ModInt  & a, LL       b) { return (a = a ^ b); }
	friend istream & operator>>(istream & s, ModInt & b) { s >> b.v; b = ModInt(b.v); return s; }
	friend ostream & operator<<(ostream & s, ModInt   b) { return (s << b.v); }
};

// ----

using MI = ModInt<1'000'000'007>;

int main() {
	auto [n] = in<int>();
	auto a = vin<MI>(n);
	
	MI s = 0, ss = 0;
	RF(e, a) {
		s += e;
		ss += e * e;
	}
	out((s * s - ss) / 2);
}
