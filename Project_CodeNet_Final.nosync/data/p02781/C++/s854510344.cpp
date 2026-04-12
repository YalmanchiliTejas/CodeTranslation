#include <iostream>
#include <string>

using namespace std;

int main(){
  string N;
  int K;
  cin >> N >> K;
  int dp[110][2][4];
  for(int i=0; i<=K; i++){
    dp[0][0][i]=0;
    dp[0][1][i]=0;
  }
  dp[0][0][0]=1;
  for(int i=1; i<=N.size(); i++){
    dp[i][0][0]=0;
    dp[i][1][0]=1;
  }
  for(int i=1; i<=N.size(); i++){
    for(int j=1; j<=K; j++){
      if(N[i-1]=='0'){
        dp[i][0][j]=dp[i-1][0][j];
        dp[i][1][j]=dp[i-1][1][j-1]*9+dp[i-1][1][j];
      }
      else{
        dp[i][0][j]=dp[i-1][0][j-1];
        dp[i][1][j]=dp[i-1][0][j-1]*(N[i-1]-'0'-1)+dp[i-1][0][j]
                    +dp[i-1][1][j-1]*9+dp[i-1][1][j];
      }
    }
  }
  cout << dp[N.size()][0][K]+dp[N.size()][1][K] << endl;

  return 0;
}
