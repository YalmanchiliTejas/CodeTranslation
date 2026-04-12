#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=998244353;
int main(){
  int64_t N,S;
  cin>>N>>S;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  vector<vector<int64_t>>dp(N+1,vector<int64_t>(S+1,0));
  for(int64_t i=1;i<=N;i++)
    for(int64_t j=1;j<=S;j++){
    if(j<A[i-1])
      dp[i][j]=dp[i-1][j];
      else
        if(j==A[i-1])
          dp[i][j]=(dp[i-1][j]+i)%mod;
      else
        dp[i][j]=(dp[i-1][j]+dp[i-1][j-A[i-1]])%mod;
    }int64_t ans=0;
  for(int64_t i=1;i<=N;i++)
    ans=(ans+dp[i][S])%mod;
  cout<<ans<<endl;
  return 0;
}