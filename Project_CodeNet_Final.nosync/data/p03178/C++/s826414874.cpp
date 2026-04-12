
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int INF=1001001001;

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

int main(){
string k;
ll d;
cin>>k>>d;
ll n=k.size();
mint dp[n+5][d+5][2];//0未満
dp[0][0][1]=1;
rep(i,n)rep(j,d){
  ll K=(k[i]-'0');
  /*
  if (K==0){
    mint temp=10*dp[i][j][0];
    dp[i+1][now][0]+=temp;
    dp[i+1][now][1]+=dp[i][j][1];
  }
  */
//  else{
    rep(z,10){
      ll now=(j+z)%d;
      if(z<K){
        dp[i+1][now][0]+=dp[i][j][0];
        dp[i+1][now][0]+=dp[i][j][1];

      }
      else if (z==K){
        dp[i+1][now][0]+=dp[i][j][0];
        dp[i+1][now][1]+=dp[i][j][1];

      }
      else{
        dp[i+1][now][0]+=dp[i][j][0];
      }
    //  cout<<"i"<<i<<"j"<<j<<"z"<<z<<endl;
//cout<<dp[i+1][now][0]<<" "<<dp[i+1][now][1]<<"now"<<now<<endl;
    }


  //}



}mint ans=0;
ans+=dp[n][0][0];
ans+=dp[n][0][1];
ans-=1;
cout<<ans;


}
