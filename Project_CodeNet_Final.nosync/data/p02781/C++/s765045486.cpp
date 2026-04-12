#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string N;
  ll K;
  cin >> N >> K;

  ll M = N.length();

  ll dp[2][K+2][M+2];
  for(ll i = 0; i < K+2; i++){
    for(ll j = 0; j < M+2; j++){
      dp[0][i][j] = 0;
      dp[1][i][j] = 0;
    }
  }
  //vector<ll> dp(M+1, 0);
  dp[0][0][1] = 1;
  dp[1][1][1] = 1;
  dp[0][1][1] = N[0] - '1';
  
  for(ll i = 0; i < M; i++){
    ll num = N[i] - '0';
    //dp[0][0][i+1] = 1;
    for(ll j = 0; j <= K; j++){
      if(num != 0)
        dp[1][j+1][i+1] += dp[1][j][i];
      else
        dp[1][j][i+1] += dp[1][j][i];
      if(num > 1){
        dp[0][j+1][i+1] += (num - 1) * dp[1][j][i];
      }
      if(num > 0)
        dp[0][j][i+1] += dp[1][j][i];

      dp[0][j+1][i+1] += 9 * dp[0][j][i];
      
      dp[0][j][i+1] += dp[0][j][i];
    }
  }
  cout << dp[0][K][M] + dp[1][K][M] << endl;
}