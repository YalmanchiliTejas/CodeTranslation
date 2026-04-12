//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 
#define MODB  998244353

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

//つねに10億7などの剰余をとる構造体
//参考: https://www.youtube.com/watch?v=L8grWxBlIZ4&t=9858
//参考: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an
int mod  = MODA;
struct modint {
	ll x;
	modint (ll x):x(x%mod){}
	modint& operator+=(const modint a){
		(x += a.x ) %= mod;
		return *this;
	}
	modint& operator-=(const modint a){
		(x -= a.x ) %= mod;
		if (x < 0) x += mod;
		return *this;
	}
	modint& operator*=(const modint a){
		(x *= a.x ) %= mod;
		return *this;
	}
	modint& operator/=(modint a){ //除算のみO(log mod)なので注意。割る数が小さいならnCrのinvを使うこと
		ll exp = mod - 2;
		while(exp > 0){ 
			if(exp & 1) *this *= a.x;
			a *= a.x;
			exp >>= 1;
		}
		return *this;
	}
	modint operator+(const modint a) const{
		modint res(*this);
		return res+=a;
	}
	modint operator-(const modint a) const{
		modint res(*this);
		return res-=a;
	}
	modint operator*(const modint a) const{
		modint res(*this);
		return res*=a;
	}
	modint operator/(const modint a) const{
		modint res(*this);
		return res/=a;
	}
};
modint modpow(modint x, ll n){
	modint res=1;
	while(n > 0){
		if(n & 1) res = res * x.x;
		x = x * x;
		n >>= 1;
	}
	return res;
}

int main() {
	modint ans = 0;
	ll tmp;
	int n; cin >> n;
	vector<ll> a(n);
	cin >> a;
	modint su = 0;
	REP(i, n) su += a[i];
	modint ss = 0;
	REP(i, n){
		ss += a[i];
		ans += a[i] * (su - ss).x;
	}
	cout << ans.x << endl;
}