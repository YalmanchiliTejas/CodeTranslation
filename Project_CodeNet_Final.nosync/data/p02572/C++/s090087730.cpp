#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

using namespace std;
// #define int long long
using ll = long long;
const int MX = 1e6;
const ll inf = 1e13;
const int mod = 1e9+7;
struct mint {
  ll x; // typedef long long ll;
mint(ll x=0):x((x%mod+mod)%mod){}
mint operator-() const { return mint(-x);}
mint& operator+=(const mint a) {
if ((x += a.x) >= mod) x -= mod;
return *this;
}
mint& operator-=(const mint a) {
if ((x += mod-a.x) >= mod) x -= mod;
return *this;
}
mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
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
mint inv() const { return pow(mod-2);}
mint& operator/=(const mint a) { return *this *= a.inv();}
mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
vector<mint> fac(MX);
vector<mint> ifac(MX);
mint comp(ll a, ll b) {
    return fac[a]/fac[b]/fac[a-b];
}
signed main() {
    int n;
    cin >>n;
    vector<int> a(n);
    mint sum = 0;
    rep(i,n) cin >> a[i];
    rep(i,n) {
        sum += a[i];
    }
    mint ans = 0;
    rep(i,n) {
        mint tmp = sum - a[i];
        tmp *=a[i];
        ans += tmp;
    }
    
    cout << ans/2 << endl;
    

    return 0;
}

