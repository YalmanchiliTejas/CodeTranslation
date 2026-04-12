#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
using ll = long long;

// auto mod int
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

mint dp[3009][3009][3];

int main(){
  int n,s;
  cin>>n>>s;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  dp[0][0][0]=1;
  rep(i,n){
    rep(j,s+1){
      dp[i+1][j][0]+=dp[i][j][0];
      dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1];
      dp[i+1][j][2]+=dp[i][j][0]+dp[i][j][1]+dp[i][j][2];
      if(j+a[i]<=s){
        dp[i+1][j+a[i]][1]+=dp[i][j][0]+dp[i][j][1];
        dp[i+1][j+a[i]][2]+=dp[i][j][0]+dp[i][j][1];
      }
    }
  }
  cout<<dp[n][s][2].x<<endl;
  return(0);
}
