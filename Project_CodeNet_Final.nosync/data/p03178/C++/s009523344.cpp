#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 1000000007;
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


mint dp[10005][105][2];

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  dp[0][0][0] = 1;
  rep(i,s.size())rep(j,n)rep(k,2){
    int nd = s[i]-'0';
    rep(d,10) {
      int ni = i+1, nj = (j+d)%n, nk = k;
      if (k == 0) {
        if (d > nd) continue;
        if (d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  mint ans = dp[s.size()][0][0];
  ans += dp[s.size()][0][1];
  ans -=1;
  cout << ans.x << endl;
  return 0;
}
