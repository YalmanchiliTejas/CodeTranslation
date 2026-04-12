#include <bits/stdc++.h>
#define int long long
using namespace std;

template<long long mod = 1000000007>
struct modint{
	long long a;

	modint() : a(0){}
	modint(long long t){
		a = t % mod;
		if(a < 0) a += mod;
	}

	operator long long() const{ return a; }

	bool operator==(const modint &x) const{ return a == x.a; }
	bool operator!=(const modint &x) const{ return a != x.a; }

	modint operator-() const{ return modint(a ? (mod - a) : 0); }
	modint operator~() const{ return pow(mod - 2); }

	modint operator+(const modint &x) const{ return modint(*this) += x; }
	modint operator-(const modint &x) const{ return modint(*this) -= x; }
	modint operator*(const modint &x) const{ return modint(*this) *= x; }
	modint operator/(const modint &x) const{ return modint(*this) /= x; }

	modint &operator+=(const modint &x){
		a += x.a;
		if(a >= mod) a -= mod;
		return *this;
	}
	modint &operator-=(const modint &x){
		a -= x.a;
		if(a < 0) a += mod;
		return *this;
	}
	modint &operator*=(const modint &x){
		a = a * x.a % mod;
		return *this;
	}
	modint &operator/=(const modint &x){
		a = a * (~x).a % mod; 
		return *this;
	}

	friend ostream &operator<<(ostream &os,const modint &x){
		return os << x.a;
	}
	friend istream &operator>>(istream &is,modint &x){
		long long t;
		is >> t;
		x = modint(t);
		return is;
	}

	modint pow(long long x) const{
		modint ret = 1,tmp = a;
		for(;x;tmp *= tmp,x >>= 1){
			if(x & 1) ret *= tmp;
		}
		return ret;
	}
};

modint<> nCr(int n,int r){
	modint<> ret = 1;
	for(int i = 0;i < r;i++) ret = ret * modint<>(n - i) / modint<>(i + 1);
	return ret;
}

modint<> dp[2010][2010],sum[2010][2010];

signed main(){
	int n,d,x;
	while(cin >> n >> d >> x,n){
		for(int i = 0;i <= min(n,d);i++){
			for(int j = 0;j <= n;j++) dp[i][j] = sum[i][j] = 0;
		}
		dp[0][0] = 1;
		for(int i = 1;i <= n;i++) sum[0][i] = 1;
		for(int i = 0;i < min(n,d);i++){
			for(int j = 0;j <= n;j++){
				dp[i + 1][j] = sum[i][j] - sum[i][max(0ll,j - x + 1)];
				sum[i + 1][j + 1] = sum[i + 1][j] + dp[i + 1][j];
			}
		}
		// for(int i = 0;i <= n;i++){
		// 	for(int j = 0;j <= n;j++) cout << dp[i][j] << " ";
		// 	cout << endl;
		// }
		modint<> ans = 0;
		for(int i = 1;i <= min(n,d);i++){
			ans += dp[i][n] * nCr(d,i);
		}
		cout << ans << endl;
	}
}
