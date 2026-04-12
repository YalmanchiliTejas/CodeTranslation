#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=10000000000000007;
const int MOD=1000000007;
int dp[5][2][300000];
signed main(){
  int n;cin>>n;
  vector<int> a(n+5,-inf);
  rep1(i,n)cin>>a[i];
  rep1(i,n){
    a[i]+=MOD;
  }
  int res=0;
  rep(i,5){
    rep(j,300000){
      dp[i][0][j]=0;
      dp[i][1][j]=0;
    }
  }
  
  rep1(i,n){
    dp[0][0][i]=dp[0][1][i-1];
    dp[0][1][i]=dp[0][0][i-1]+a[i];
    dp[1][0][i]=max(dp[0][0][i-1],dp[1][1][i-1]);
    dp[1][1][i]=dp[1][0][i-1]+a[i];
    dp[2][0][i]=max(dp[2][1][i-1],max(-inf,dp[1][0][i-1]));
    dp[2][1][i]=dp[2][0][i-1]+a[i];
    if(i<=1){
      dp[1][1][i]=0;
      //dp[1][0][i]=0;
    }
    if(i<=1){
      dp[2][1][i]=0;
      //dp[2][0][i]=0;
    }
  }
  	if(n%2==0){
      cout<<max(dp[0][1][n],max(dp[0][0][n],dp[1][1][n]))-MOD*n/2<<endl;
    }
    else{
      //exit(1);
      res=max(max(-dp[2][0][n],dp[2][1][n]),max(dp[1][1][n],dp[1][0][n]));
      if(res==-dp[2][0][n])exit(1);
      cout<<res-n/(int)2*MOD<<endl;
      //cout<<dp[2][0][n]<<"\n";
      //cout<<dp[2][1][n]<<"\n";
    }
  return 0;
}
