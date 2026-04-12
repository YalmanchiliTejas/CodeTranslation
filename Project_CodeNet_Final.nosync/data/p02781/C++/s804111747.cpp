#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<int> N;
  string in;
  cin >> in;
  for(char c : in){
    N.push_back(c - '0');
  }
  
  int K;
  cin >> K;
  
  long long dp[N.size()][K + 1][2];
  for(int k = 0; k <= K; k++){
    dp[0][k][0] = 0;
    dp[0][k][1] = 0;
  }
  
  dp[0][0][0] = 1;
  dp[0][1][1] = 1;
  dp[0][1][0] = N[0] - 1;
  
  for(int i = 1; i < N.size(); i++){
    dp[i][0][0] = 1;
    dp[i][0][1] = 0;
    
    for(int k = 1; k <= K; k++){
      dp[i][k][0] = dp[i - 1][k][0];
      if(N[i]) dp[i][k][0] += dp[i - 1][k][1] + (N[i] - 1) * dp[i - 1][k - 1][1];
      dp[i][k][0] += 9 * dp[i - 1][k - 1][0];
      
      if(N[i]) dp[i][k][1] = dp[i - 1][k - 1][1];
      else dp[i][k][1] = dp[i - 1][k][1];
    }
  }
  
  cout << dp[N.size() - 1][K][0] + dp[N.size() - 1][K][1] << endl;
  
  return 0;
}