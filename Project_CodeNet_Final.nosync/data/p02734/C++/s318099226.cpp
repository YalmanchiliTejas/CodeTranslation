#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (int)(n); i++)
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 998244353;
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

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}


int main() {
    ll n,s;
    cin>>n>>s;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    vector<mint> q(s+1);
    mint ans=0;
    rep(i,n){
      //Lがiにくる
      q[0]+=1;
      vector<mint> q2(s+1);
      //Lがi-1以下、Rがi
      q2=q;
      rep(j,s+1){
        if(j+a[i]<=s) q2[j+a[i]]+=q[j];
      }
      q=q2;
      ans+=q[s];


    }
cout<<ans<<endl;
}
