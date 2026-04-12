#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T = int> void print(vector<T> v){for(auto a:v)cout<<a<<" ";cout<<endl;}

/*
*/

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) { }
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}
};
typedef ModInt<998244353> mint;
mint modpow(ll _a, ll n) {
	mint r=1,a=_a;
	while(n){
		r*=((n%2)?a:1);
		a*=a;
		n>>=1;
	}
	return r;
}


ll n,s,a[3010],ans=0;
mint dp[3010][6010][3];

int main(void){
	cin>>n>>s;
	reg(i,1,n)cin>>a[i];
	dp[0][0][0]=1;
	reg(i,1,n){
		dp[i][0][0] += dp[i-1][0][0];  // 現状維持
		dp[i][0][1] += dp[i-1][0][0];
		dp[i][a[i]][1] += dp[i-1][0][0];
		dp[i][0][2] += dp[i-1][0][0];
		dp[i][a[i]][2] += dp[i-1][0][0];
		rep(j,s+1){
			dp[i][j][1] += dp[i-1][j][1];  // 現状維持
			dp[i][j+a[i]][1] += dp[i-1][j][1];
			dp[i][j][2] += dp[i-1][j][1];
			dp[i][j+a[i]][2] += dp[i-1][j][1];
			dp[i][j][2] += dp[i-1][j][2];  // 現状維持
		}
	}
	// reg(i,1,n){
	// 	rep(j,s+1)cerr<<dp[i][j][0]<<" ";
	// 	cerr<<endl;
	// }
	// cerr<<"-"<<endl;
	// reg(i,1,n){
	// 	rep(j,s+1)cerr<<dp[i][j][1]<<" ";
	// 	cerr<<endl;
	// }
	// cerr<<"-"<<endl;
	// reg(i,1,n){
	// 	rep(j,s+1)cerr<<dp[i][j][2]<<" ";
	// 	cerr<<endl;
	// }
	cout<<dp[n][s][2].get()<<endl;
	return 0;
}