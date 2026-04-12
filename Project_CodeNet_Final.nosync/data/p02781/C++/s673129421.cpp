#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string n;cin>>n;
  ll k,l=n.length();cin>>k;
  lvector dgt(l,0); rep(i,l) dgt[i]+=n[i]-'0';
  reverse(dgt.begin(),dgt.end());
  ll dp[l+1][k+1][2]; memset(dp,0,sizeof(dp));
  dp[0][0][0]=1;
  for(ll i=1;i<=l;++i) {
    ll v=dgt[i-1];
    rep(j,k+1) dp[i][j][0]+=dp[i-1][j][0];
    if(v>0) rep(j,k+1) dp[i][j][0]+=dp[i-1][j][1];
    else    rep(j,k+1) dp[i][j][1]+=dp[i-1][j][1];
    for(ll x=1;x<10;++x) {
      if(x<v) 
        for(ll j=1;j<=k;++j) dp[i][j][0]+=dp[i-1][j-1][0]+dp[i-1][j-1][1];
      else if(x==v)
        for(ll j=1;j<=k;++j) {
          dp[i][j][0]+=dp[i-1][j-1][0];
          dp[i][j][1]+=dp[i-1][j-1][1];
        }
      else 
        for(ll j=1;j<=k;++j) dp[i][j][1]+=dp[i-1][j-1][0]+dp[i-1][j-1][1];
    }
  }
  print(dp[l][k][0]);
  return 0;
}