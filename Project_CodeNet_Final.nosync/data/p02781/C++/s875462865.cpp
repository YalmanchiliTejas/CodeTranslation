#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int K;
  cin>>S>>K;
  int L=S.size();
  vector<vector<int>> dp(L+2,vector<int>(K+1));
  int X=0;
  for(int i=0;i<L;i++){
    int A=S[i]-'0';
    for(int j=0;j<K;j++){
      dp[i+1][j+1]=dp[i][j+1]+9*dp[i][j];
    }
    dp[i+2][0]=1;
    if(A){
      X++;
      if(X<=K){
        dp[i+1][X]+=A-1;
        dp[i+1][X-1]++;
      }
    }
  }
  if(X>=K){
    dp[L][K]++;
  }
  cout<<dp[L][K]<<endl;
    
}