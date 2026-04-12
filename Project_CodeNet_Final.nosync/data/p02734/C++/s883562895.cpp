#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,S,a,dp[3002][3002],ans=0,MOD=998244353;
  cin>>N>>S;
  dp[0][0]=1;
  for(int i=1;i<=N;i++){
    cin>>a;
    for(int j=0;j<=S;j++){
      dp[i][j]=dp[i-1][j];
      if(j>=a)dp[i][j]+=dp[i-1][j-a];
      dp[i][j]%=MOD;
    }
    dp[i][0]++;
    ans+=dp[i][S];
    ans%=MOD;
  }
  cout<<ans<<endl;
}
