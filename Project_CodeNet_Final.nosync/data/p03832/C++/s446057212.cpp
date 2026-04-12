#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>
#include <cmath>
#include <cassert>
#include <bitset>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define EL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

constexpr int MOD = 1e9+7;
struct mint
{
	int v;
	mint():v(0){}
	mint(int v):v((v+MOD)%MOD){}
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
	mint pow(int k)const{ mint r(1),t(v); while(k){ if(k&1) r*=t; t*=t; k>>=1; } return r; }
	mint inv()const{ return pow(MOD-2); }
	static mint comb(int n, int k) {
		if(n-k<k) k=n-k;
		mint num(1), dom(1);
		for(int i=0;i<k;i++) { num*=n-i; dom*=i+1; }
		return num/dom;
	}
};
std::istream& operator>>(std::istream&i,mint&a){ int t; i>>t; a=mint(t); return i; }
std::ostream& operator<<(std::ostream&o,const mint&a){ o<<a.v; return o; }


signed main() {
	int n,a,b,c,d;
	std::cin >> n >> a >> b >> c >> d;
	std::vector<mint> fact(n+1,1);
	for(int i=2;i<=n;i++) fact[i]=fact[i-1]*mint(i);
	std::vector<std::vector<mint> > dp(n+1,std::vector<mint>(n+1,0));
	dp[0][0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			dp[i][j]+=dp[i-1][j];
			if(i<a || b<i) continue;
			for(int k=c;k<=d;k++) {
				if(j-i*k<0) break;
				dp[i][j]+=dp[i-1][j-i*k]*fact[j]/fact[j-i*k]/fact[i].pow(k)/fact[k];
			}
		}
	}
	print(dp[n][n]);
	return 0;
}
