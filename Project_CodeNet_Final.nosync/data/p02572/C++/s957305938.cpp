//abc177_c.cpp
//Sat Aug 29 20:53:38 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

struct mint {
	ll x; // typedef long long ll;
	mint(ll x=0):x((x%MOD+MOD)%MOD){}
	mint operator-() const { return mint(-x);}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += MOD-a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const { return pow(MOD-2);}
	mint& operator/=(const mint a) { return *this *= a.inv();}
	mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}


int main(){
	ll n;
	cin >> n;

	mint a[n];
	mint sum[n];
	rep(i,n){
		cin >> a[i];
		if (i==0){
			sum[0] = a[0];
		}else {
			sum[i] = sum[i-1]+a[i];
		}
	}

	mint ans = 0;
	for(int i=n-1;i>0;i--){
		ans += a[i]*sum[i-1];
	}


	cout << ans << endl;
//	printf("%.4f\n",ans);
}