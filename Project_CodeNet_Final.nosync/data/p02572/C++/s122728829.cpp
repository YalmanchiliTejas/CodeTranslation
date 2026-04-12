#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <functional>
#include <bitset>
#include <limits>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <random>

#ifdef DEBUG
#include "library/Utility/debug.cpp"
#else
#define debug(...)
#endif

#define rep(i,n) for(int i=0;i<(n);++i)
#define EL '\n'
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
using lnt = long long;
struct FIO{FIO(){std::cin.tie(0);std::ios_base::sync_with_stdio(0);std::cout<<std::setprecision(15);}}fIO;
template<typename T> using V = std::vector<T>;
template<typename T> void fill(V<T>&v) { for(T&e:v) std::cin >> e; }
/*-*/

constexpr lnt MOD = 1e9+7;
struct mint
{
	lnt v;
	mint():v(0){}
	mint(lnt v):v((v+MOD)%MOD){}
	mint operator-()const{ return mint(0) - *this; }
	mint& operator+=(const mint& a){ if((v+=a.v)>=MOD) v-=MOD; return *this; }
	mint& operator-=(const mint& a){ if((v+=MOD-a.v)>=MOD) v-=MOD; return *this; }
	mint& operator*=(const mint& a){ (v*=a.v)%=MOD; return *this; }
	mint& operator/=(const mint& a){ (*this) *= a.inv(); return *this; }
	mint operator+(const mint& a)const{ return mint(*this) += a; }
	mint operator-(const mint& a)const{ return mint(*this) -= a; }
	mint operator*(const mint& a)const{ return mint(*this) *= a; }
	mint operator/(const mint& a)const{ return mint(*this) /= a; }
	bool operator<(const mint& a)const{ return v < a.v; }
	bool operator==(const mint& a)const{ return v == a.v; }
	mint pow(lnt k)const{ mint r(1),t(v); while(k){ if(k&1) r*=t; t*=t; k>>=1; } return r; }
	mint inv()const{ return pow(MOD-2); }
	static mint comb(lnt n, lnt k) { if(n-k<k) k=n-k; mint num(1), dom(1); for(int i=0;i<k;i++) { num*=n-i; dom*=i+1; } return num/dom; }
	static std::vector<mint> construct_comb(int n) {
		std::vector<mint> c(n+1); mint a = 1; c[0] = a; for(int i=1;i<=n;i++) { a = a*mint(n+1-i)/i; c[i] = a; } return c;
	}
	static std::vector<mint> construct_fact(int n) { std::vector<mint> f(n+1,1); for(int i=2;i<=n;i++) f[i]=f[i-1]*i; return f; }
};
std::istream& operator>>(std::istream&i,mint&a){ lnt t; i>>t; a=mint(t); return i; }
std::ostream& operator<<(std::ostream&o,const mint&a){ o<<a.v; return o; }


int main() {
	int n;
	std::cin >> n;
	V<mint> a(n);
	fill(a);
	mint sum=0;
	rep(i,n) sum+=a[i];
	mint ans=0;
	rep(i,n) {
		sum-=a[i];
		ans+=a[i]*sum;
	}
	print(ans);
}
