//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  string s;cin>>s;
  ll n=s.size();
  ll k;cin>>k;
  ll dp[110][4][2];
  rep(i,n){
    rep(j,4){
      rep(k,2)dp[i][j][k]=0;
    }
  }
  dp[0][1][0]=s[0]-'0'-1;
  dp[0][1][1]=1;
  for(ll i=1;i<n;i++){
    for(ll j=1;j<4;j++){
      if(s[i]=='0'){
        dp[i][j][1]+=dp[i-1][j][1];
      }
      else {
        dp[i][j][1]+=dp[i-1][j-1][1];
        dp[i][j][0]+=(s[i]-'0'-1)*dp[i-1][j-1][1];
        dp[i][j][0]+=dp[i-1][j][1];
      }
      dp[i][j][0]+=9*dp[i-1][j-1][0];
      dp[i][j][0]+=dp[i-1][j][0];
    }
    dp[i][1][0]+=9;
  }
  ll ans=0;
  
  ans+=dp[n-1][k][0];
  ans+=dp[n-1][k][1];
  
  cout<<ans<<endl;
  //rep(i,4){
    //rep(j,4){
      //rep(t,2)cout<<dp[i][j][t]<<" ";
    //}
    //cout<<endl;
  //}
}
  
