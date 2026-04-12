#include <bits/stdc++.h>
using namespace std;

int64_t Q=998244353;

int main(){
  int N,S;
  cin>>N>>S;
  vector<vector<int64_t>> dp(N+1,vector<int64_t>(3000+1));
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  dp[1][0]=1,dp[1][p[0]]=1;
  for(int i=1;i<N;i++){
    for(int j=0;j<=S;j++){
      dp[i+1][j]=(Q+dp[i][j]-dp[i-1][j])%Q;
    }
    for(int j=S;j>=p[i];j--){
      dp[i+1][j]+=dp[i+1][j-p[i]];
      dp[i+1][j]%=Q;
    }
    for(int j=0;j<=S;j++){
      dp[i+1][j]+=dp[i][j];
      dp[i+1][j]%=Q;
    }
    dp[i+1][0]++,dp[i+1][p[i]]++;
  }
  cout<<dp[N][S]<<endl;
}