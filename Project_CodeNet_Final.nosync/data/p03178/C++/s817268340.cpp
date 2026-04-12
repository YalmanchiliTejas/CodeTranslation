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
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
int main(){
  string k;ll d;cin>>k>>d;
  //ll dp[10010][2][110];
  vector<vvl> dp(10010,vvl(2,vl(110)));
  dp[0][0][0]=1;
  ll n=k.size();
  rep(i,n){
    rep(j,d){
      rep(dig,10){
        dp[i+1][1][(j+dig)%d]+=dp[i][1][j];
        dp[i+1][1][(j+dig)%d]%=MOD;
      }
      rep(dig,k[i]-'0'){
        dp[i+1][1][(j+dig)%d]+=dp[i][0][j];
        dp[i+1][1][(j+dig)%d]%=MOD;
      }
      dp[i+1][0][(j+(k[i]-'0'))%d]+=dp[i][0][j];
      dp[i][0][j]%=MOD;

    }

  }
  //rep(i,n+1){
    //rep(j,d){
      //cout<<dp[i][1][j]<<" "<<dp[i][0][j]<<" ";
    //}
    //cout<<endl;
  //}
  cout<<(dp[n][0][0]+dp[n][1][0]-1+MOD)%MOD<<endl;

  
}