#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll mod = 1000000007;
struct mint{
	ll x;
	mint(ll x = 0):x((x%mod+mod)%mod){}
	mint operator-() const{return mint(-x);}
	mint& operator+=(const mint a){
		if((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a){
		if((x += mod-a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a){
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const{
		mint res(*this);
		return res+=a;
	}
	mint operator-(const mint a) const{
		mint res(*this);
		return res-=a;
	}
	mint operator*(const mint a) const{
		mint res(*this);
		return res*=a;
	}
	mint pow(ll t) const{
		if(!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if(t&1) a *= *this;
		return a;
	}
	mint inv() const{
		return pow(mod-2);
	}
	mint& operator/=(const mint a){
		return (*this) *= a.inv();
	}
	mint operator/(const mint a) const{
		mint res(*this);
		return res/=a;
	}
	bool operator==(const mint a){
		return x == a.x;
	}
};

struct Combination{
	vector<mint> fact, ifact;
	Combination(int n):fact(n+1),ifact(n+1){
		assert(n < mod);
		fact[0] = 1;
		for(int i = 1; i <= n; i++) fact[i] = fact[i-1]*i;
		ifact[n] = fact[n].inv();
		for(int i = n; i >= 1; i--) ifact[i-1] = ifact[i]*i;
	}
	mint operator()(int n, int k){
		if(k < 0 || k > n) return 0;
		return fact[n]*ifact[k]*ifact[n-k];
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	Combination comb(1000000);
	mint ans = 0;
	for(ll i = 1; i <= n; ++i){
		mint add = i * (n - i) % mod * m % mod * m % mod;
		add *= comb(n*m-2, k-2);
		ans += add;
	}
	for(ll i = 1; i <= m; ++i){
		mint add = i * (m - i) % mod * n % mod * n % mod;
		add *= comb(n*m-2, k-2);
		ans += add;
	}
	cout << ans.x << endl;
	return 0;
}