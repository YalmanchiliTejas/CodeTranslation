#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define per(i,n) for (int i=n-1; i>=0; --i)
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using vi = vector<int>;
using vv = vector<vi>;
const int mod = 1000000007;
//const int mod = 998244353;

struct mint{
    ll x;
    mint(ll x=0):x(x%mod){}
    
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x-= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if(t&1) a *= *this;
        return a;
    }
    
    //modが素数の場合
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

int main(){
    int n;
    cin >> n;
    mint sum = 0, sum2 = 0;
    rep(i,n){
        ll a;
        cin >> a;
        sum  += a;
        sum2 += mint(a)*a;
    }
    mint ans = ( sum*sum - sum2 ) / 2;
    
    cout << ans.x << endl;
    return 0;
}