#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
#define incID(i, l, r) for(int i = (l)    ; i <  (r); ++i)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); --i)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); ++i)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); --i)
#define inc(i, n)  incID(i, 0, n)
#define dec(i, n)  decID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define dec1(i, n) decII(i, 1, n)
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))
#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define PB push_back
#define EB emplace_back
#define MP make_pair
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
#define SI(v) static_cast<int>(v.size())
#define RF(e, v) for(auto & e: v)
#define until(e) while(! (e))
#define if_not(e) if(! (e))
#define ef else if
#define UR assert(false)
#define IN(T, ...) T __VA_ARGS__; IN_(__VA_ARGS__);
void IN_() { };
template<typename T, typename ... U> void IN_(T & a, U & ... b) { cin >> a; IN_(b ...); };
template<typename T> void OUT(T && a) { cout << a << endl; }
template<typename T, typename ... U> void OUT(T && a, U && ... b) { cout << a << " "; OUT(b ...); }

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

using MI = ModInt< 998244353 >;

template<typename T> istream & operator>>(istream & s, vector<T> & v) { RF(e, v) { s >> e; } return s; }
template<typename T> ostream & operator<<(ostream & s, vector<T> const & v) {
	inc(i, SI(v)) { s << (i == 0 ? "" : " ") << v[i]; }
	return s;
}

template<typename T> T MV(T v) { return v; }
template<typename T, typename ... U> auto MV(T v, int a, U ... b) { return vector<decltype(MV(v, b ...))>(a, MV(v, b ...)); }

int main() {
	IN(int, n, s);
	vector<int> a(n);
	cin >> a;
	
	auto dp = MV<MI>(0, n + 1, s + 1);
	MI ans = 0;
	inc(i, n) {
		dp[i][0] += 1;
		inc(j, s + 1) {
			dp[i + 1][j] += dp[i][j];
			if(j + a[i] <= s) { dp[i + 1][j + a[i]] += dp[i][j]; }
		}
		ans += dp[i + 1][s];
	}
	
	OUT(ans);
}
