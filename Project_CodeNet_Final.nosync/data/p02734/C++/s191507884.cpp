#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

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
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
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
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  rep(snip_i, n) cin >> a.at(snip_i);
  vector<vector<mint>> dp(n+1, vector<mint>(s+1, 0));
  dp.at(0).at(0) = 1;
  rep(i,n){
    int now = a.at(i);
    rep(j, s+1){
      dp.at(i+1).at(j) += dp.at(i).at(j);
      if(now + j <= s) dp.at(i+1).at(now+j) += dp.at(i).at(j);
    }
    dp.at(i+1).at(0) += 1;
  }

  // rep(i, n+1){
  //   rep(j, s+1){
  //     cerr << dp.at(i).at(j).x << " ";
  //   }
  //   cerr << endl;
  // }

  mint ans = 0;
  rep(i, n+1){
    ans += dp.at(i).at(s);
  }
  cout << ans.x << endl;
  return 0;
}