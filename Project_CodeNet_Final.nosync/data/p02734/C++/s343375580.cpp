#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
  int N,S,ans=0,dp[3001][3001];
  cin>>N>>S;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  dp[0][0]=1;
  for(int i=1;i<=N;i++){
    for(int j=0;j<=S;j++){
      if(dp[i-1][j]>0){dp[i][j]=dp[i-1][j];}
      if(j-A.at(i-1)>=0 && dp[i-1][j-A.at(i-1)]>0){dp[i][j]+=dp[i-1][j-A.at(i-1)];}
      dp[i][j]%=MOD;
    }
    dp[i][0]++;
    ans+=dp[i][S];
    ans%=MOD;
  }
  cout<<ans<<endl;
}