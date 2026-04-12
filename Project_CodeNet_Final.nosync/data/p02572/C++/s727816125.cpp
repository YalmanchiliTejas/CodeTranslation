#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod = 1000000007;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    mint sum = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    mint ans = 0;
    rep(i,n){
        ans += (sum + mod - a[i]) * a[i];
        sum = sum + mod - a[i];
    }
    cout << ans.x << endl;
    return 0;
}