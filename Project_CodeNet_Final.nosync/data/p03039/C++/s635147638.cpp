#include <bits/stdc++.h>
using namespace std;
typedef long long   signed int LL;
typedef long long unsigned int LU;
#define incID(i, l, r) for(LL i = (l)    ; i <  (r); ++i)
#define incII(i, l, r) for(LL i = (l)    ; i <= (r); ++i)
#define decID(i, l, r) for(LL i = (r) - 1; i >= (l); --i)
#define decII(i, l, r) for(LL i = (r)    ; i >= (l); --i)
#define inc(i, n)  incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define dec(i, n)  decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))
#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
template<typename T> bool setmin  (T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmax  (T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }
template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }
LL mo(LL a, LL b) { assert(b > 0); a %= b; if(a < 0) { a += b; } return a; }
LL fl(LL a, LL b) { assert(b > 0); return (a > 0 ? a / b : (a - b + 1) / b); }
LL ce(LL a, LL b) { assert(b > 0); return (a < 0 ? a / b : (a + b - 1) / b); }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define bit(b, i) (((b) >> (i)) & 1)
#define BC __builtin_popcountll
#define SC static_cast
#define SI(v) SC<int>(v.size())
#define SL(v) SC<LL >(v.size())
#define RF(e, v) for(auto & e: v)
#define ef else if
#define UR assert(false)

// ---- ----

template<LL M> class ModInt {
private:
	LL v = 0;
public:
	ModInt() { }
	ModInt(LL vv) { setval(vv); }
	ModInt & setval(LL vv) { v = vv % M; if(v < 0) { v += M; } return (*this); }
	LL getval() const { return v; }
	ModInt & operator+=(const ModInt & b)       { return setval(v + b.v); }
	ModInt & operator-=(const ModInt & b)       { return setval(v - b.v); }
	ModInt & operator*=(const ModInt & b)       { return setval(v * b.v); }
	ModInt & operator/=(const ModInt & b)       { return setval(v * b.inv()); }
	ModInt & operator^=(            LU b)       { return setval(ex(v, b)); }
	ModInt   operator+ (                ) const { return ModInt(+v); }
	ModInt   operator- (                ) const { return ModInt(-v); }
	ModInt   operator+ (const ModInt & b) const { return ModInt(v + b.v); }
	ModInt   operator- (const ModInt & b) const { return ModInt(v - b.v); }
	ModInt   operator* (const ModInt & b) const { return ModInt(v * b.v); }
	ModInt   operator/ (const ModInt & b) const { return ModInt(v * b.inv()); }
	ModInt   operator^ (            LU b) const { return ModInt(ex(v, b)); }
	LL inv() const {
		LL x = (ex_gcd(v, M).FI + M) % M;
		assert(v * x % M == 1);
		return x;
	}
	LL ex(LL a, LU b) const {
		LL D = 64, x[64], y = 1;
		inc(i, D) { if((b >> i) == 0) { D = i; break; } }
		inc(i, D) { x[i] = (i == 0 ? a : x[i - 1] * x[i - 1]) % M; }
		inc(i, D) { if((b >> i) & 1) { (y *= x[i]) %= M; } }
		return y;
	}
	pair<LL, LL> ex_gcd(LL a, LL b) const {
		if(b == 0) { return MP(1, 0); }
		auto p = ex_gcd(b, a % b);
		return MP(p.SE, p.FI - (a / b) * p.SE);
	}
};
template<LL M> ModInt<M> operator+(LL a, const ModInt<M> & b) { return  b + a; }
template<LL M> ModInt<M> operator-(LL a, const ModInt<M> & b) { return -b + a; }
template<LL M> ModInt<M> operator*(LL a, const ModInt<M> & b) { return  b * a; }
template<LL M> ModInt<M> operator/(LL a, const ModInt<M> & b) { return  a * b.inv(); }
template<LL M> istream & operator>>(istream & is, ModInt<M> & b) { LL v; is >> v; b.setval(v); return is; }
template<LL M> ostream & operator<<(ostream & os, const ModInt<M> & b) { return (os << b.getval()); }

// ---- ----

typedef ModInt<1'000'000'007> MI;

MI comb(LL x, LL y) {
	MI p = 1;
	inc(i, y) {
		p *= x - i;
		p /= i + 1;
	}
	return p;
}

int main() {
	LL n, m, k;
	cin >> n >> m >> k;
	
	MI a2 = 0;
	incII(i, 0, n) { a2 += i * 2 * (n - i) * m * m; }
	incII(i, 0, m) { a2 += i * 2 * (m - i) * n * n; }
	a2 /= 2;
	
	MI ans = a2 * comb(n * m - 2, k - 2);
	
	cout << ans << endl;
	
	return 0;
}
