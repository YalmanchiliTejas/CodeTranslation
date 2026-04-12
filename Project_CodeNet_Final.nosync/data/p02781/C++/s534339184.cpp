#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

ll dp[111][2][10];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string N; cin>>N;
  int NN=N.length();
  int K; cin>>K;
  dp[0][0][0]=1;
  rep(i,NN) rep(j,2) rep(k,K+1){
    int n=N[i]-'0';
    if(j==0){
      if(n){
        dp[i+1][0][k+1]+=dp[i][j][k];
        dp[i+1][1][k]+=dp[i][j][k];
        dp[i+1][1][k+1]+=max(0,n-1)*dp[i][j][k];
      }else{
        dp[i+1][0][k]+=dp[i][j][k];
      }
    }else{
      dp[i+1][1][k]+=dp[i][j][k];
      dp[i+1][1][k+1]+=9*dp[i][j][k];
    }
  }

  cout<<dp[NN][0][K]+dp[NN][1][K]<<endl;
  return 0;
}