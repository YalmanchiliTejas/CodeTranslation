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
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
const int inf=1000000007;
const int MOD=1000000007;
int dp[10][2][1000];
signed main(){
  string s;int k;cin>>s>>k;
  rep(i,10){
    rep(j,2){
      rep(kk,1000)dp[i][j][kk]=0;
    }
  }
  int n=(int)s.length();
  int res=0;int start=0;
  rep(i,n){
    if(i==0){
      dp[1][0][i]=s[i]-'1';
      dp[0][0][0]=1;
      dp[1][1][0]=1;
    }
    else{
      dp[0][0][i]=dp[0][0][i-1];
      dp[1][0][i]=dp[1][0][i-1];
      dp[2][0][i]=dp[2][0][i-1];
      dp[3][0][i]=dp[3][0][i-1];
      dp[1][0][i]+=dp[0][0][i-1]*9;
      dp[2][0][i]+=dp[1][0][i-1]*9;
      dp[3][0][i]+=dp[2][0][i-1]*9;
      if(s[i]!='0'){
      dp[0][0][i]+=dp[0][1][i-1];
      dp[1][0][i]+=dp[1][1][i-1];
      dp[2][0][i]+=dp[2][1][i-1];
      dp[3][0][i]+=dp[3][1][i-1];
      dp[1][0][i]+=dp[0][1][i-1]*(s[i]-'1');
      dp[2][0][i]+=dp[1][1][i-1]*(s[i]-'1');
      dp[3][0][i]+=dp[2][1][i-1]*(s[i]-'1');
      dp[1][1][i]+=dp[0][1][i-1];
      dp[2][1][i]+=dp[1][1][i-1];
      dp[3][1][i]+=dp[2][1][i-1];
      }
      else{
        dp[0][1][i]=dp[0][1][i-1];
        dp[1][1][i]=dp[1][1][i-1];
        dp[2][1][i]=dp[2][1][i-1];
        dp[3][1][i]=dp[3][1][i-1];
      }
    }
  }
  //cout<<"ok"<<endl;
  cout<<dp[k][0][n-1]+dp[k][1][n-1]<<endl;
  return 0;
}
