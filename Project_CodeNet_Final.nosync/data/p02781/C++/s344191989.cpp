#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for(ll i = 0;i < n;i++)
#define ll long long
#define MOD 1000000007
#define llMAX 9223372036854775807
#define llMIN -9223372036854775808
using vi = vector<ll>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vvvi = vector<vvi>; // intの2次元の型に vvi という別名をつける


ll k,x,y;

int main(){
  ll ans=0;
  string n;
  cin >> n >> k;
  ll nl=n.length();

  vi a(nl);
  REP(i,nl){
    a[i]=n[nl-1-i]-48;
  }

  vvvi dp = vvvi(nl, vvi(4, vi(2, 0)));
  REP(i,nl){
    dp[i][0][0]=1;
    dp[i][0][1]=1;
  }

  dp[0][1][0]=a[0];
  dp[0][1][1]=9LL;
  
  dp[0][2][0]=0;
  dp[0][2][1]=0;
  dp[0][3][0]=0;
  dp[0][3][1]=0;

  for(ll j=1;j<4;j++){
    for(ll i=1;i<nl;i++){
      if (a[i]!=0){
        dp[i][j][0]=dp[i-1][j-1][0]+(a[i]-1LL)*dp[i-1][j-1][1]+dp[i-1][j][1];
      }else{
        dp[i][j][0]=dp[i-1][j][0];
      }
      dp[i][j][1]=dp[i-1][j][1]+9LL*dp[i-1][j-1][1];
    }
  }

  cout<<dp[nl-1][k][0]<<endl;
  return 0;
}