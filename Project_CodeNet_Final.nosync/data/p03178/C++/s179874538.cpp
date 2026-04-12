
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
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
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
    //a^tを求める
    //例：d[i] = mint(k/i).pow(n);
    //mint(2).pow(n); 2^n
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

mint dp[10005][105][2];//1 未満


ll F(ll d, ll k){
  while(k<0)k+=d;
  return k;
}
int main() {
  string k;
  ll d;
  cin>>k>>d;
  vector<ll>s(k.size());
  rep(i,k.size())s[i]=k[i]-'0';
  rep(i,10005)rep(q,105)rep(j,2)dp[i][q][j]=0;
  dp[0][0][0]=1;

  rep(i,k.size())rep(j,d){

  //  if ((j-s[i])<0){
      //s[i]-=10;

  //  dp[i+1][j][0]+=dp[i][j-s[i]+d][0];
//


      dp[i+1][j][0]+=dp[i][F(d,j-s[i])][0];


     rep(q,10){
    //   cout<<j-k+d<<' '<<dp[i][j-k+d][1]<<endl;
      // if ((j-k)<0) dp[i+1][j][1]+=dp[i][j-k+d][1];
        dp[i+1][j][1]+=dp[i][F(d,j-q)][1];
    //   cout<<dp[i+1][j][1]<<'q'<<q<<endl;
      }
      rep(q,s[i]){
      //  if ((j-q)<0) dp[i+1][j][1]+=dp[i][j-q+d][0];
         dp[i+1][j][1]+=dp[i][F(d,j-q)][0];
      //   cout<<dp[i+1][j][1]<<'q'<<q<<endl;

       }


       //cout<<dp[i+1][j][0]<<' '<<dp[i+1][j][1]<<'i'<<i<<'j'<<j<<endl;
}

mint ans=dp[k.size()][0][1];
ans+=dp[k.size()][0][0];
ans-=1;
cout<<ans.x;
}
