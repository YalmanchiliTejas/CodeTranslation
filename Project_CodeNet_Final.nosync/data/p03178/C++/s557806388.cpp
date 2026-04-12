#include <bits/stdc++.h>
using namespace std;

typedef long long   signed int LL;
typedef long long unsigned int LU;

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define  inc(i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define  dec(i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define PQ priority_queue

#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
#define  FOR(it, v) for(auto it =  v.begin(); it !=  v.end(); ++it)
#define RFOR(it, v) for(auto it = v.rbegin(); it != v.rend(); ++it)

template<typename T> bool   setmin(T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }
template<typename T> bool   setmax(T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }
template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

template<int N = 0> class ModInt {
private:
	LL v = 0;
	static LL m;
public:
	ModInt() { }
	ModInt(LL vv) { setval(vv); }
	ModInt & setval(LL vv) { v = vv % m; if(v < 0) { v += m; } return (*this); }
	static void setmod(LL mm) { m = mm; }
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
		LL x = (ex_gcd(v, m).FI + m) % m;
		assert(v * x % m == 1);
		return x;
	}
	LL ex(LL a, LU b) const {
		LL D = 64, x[64], y = 1;
		inc(i, D) { if((b >> i) == 0) { D = i; break; } }
		inc(i, D) { x[i] = (i == 0 ? a : x[i - 1] * x[i - 1]) % m; }
		inc(i, D) { if((b >> i) & 1) { (y *= x[i]) %= m; } }
		return y;
	}
	pair<LL, LL> ex_gcd(LL a, LL b) const {
		if(b == 0) { return MP(1, 0); }
		auto p = ex_gcd(b, a % b);
		return MP(p.SE, p.FI - (a / b) * p.SE);
	}
};
template<int N> LL ModInt<N>::m;
template<int N> ModInt<N> operator+(LL a, const ModInt<N> & b) { return  b + a; }
template<int N> ModInt<N> operator-(LL a, const ModInt<N> & b) { return -b + a; }
template<int N> ModInt<N> operator*(LL a, const ModInt<N> & b) { return  b * a; }
template<int N> ModInt<N> operator/(LL a, const ModInt<N> & b) { return  a * b.inv(); }
template<int N> istream & operator>>(istream & is, ModInt<N> & b) { LL v; is >> v; b.setval(v); return is; }
template<int N> ostream & operator<<(ostream & os, const ModInt<N> & b) { return (os << b.getval()); }

// ---- ----

string s;
int L, d;
ModInt<> dp[100002][2][100];

int main() {
	ModInt<>::setmod(1e9 + 7);
	cin >> s >> d;
	L = s.size();
	
	dp[0][0][0] = 1;
	inc(i, L) {
		inc(j, d) {
			{  int k = (s[i] - '0');  dp[i + 1][0][(j + k) % d] += dp[i][0][j]; }
			incID(k, 0, s[i] - '0') { dp[i + 1][1][(j + k) % d] += dp[i][0][j]; }
			inc(k, 10)              { dp[i + 1][1][(j + k) % d] += dp[i][1][j]; }
		}
	}
	
	cout << (dp[L][0][0]) + (dp[L][1][0] - 1) << endl;
	
	return 0;
}
