#include <bits/stdc++.h>
using namespace std;

int main() {
  // dp[i][j][k]
  // kは0以外の桁数0,1,2,3,4以上の5種類
  int dp[120][2][5] = {};
  
  string N;
  int K;
  cin >> N >> K;
  vector<int> n(N.size());
  for(int i = 0; i < N.size(); ++i){
    n.at(i) = N.at(i) - '0';
  }

  dp[0][0][0] = 1;
  for(int i = 0; i < n.size(); ++i){
    for(int j = 0; j < 2; ++j){
      for(int k = 0; k < 5; ++k){
        for(int x = 0; x <= (j ? 9 : n.at(i)); ++x){
          dp[i+1][j || x < n.at(i)][min(k + (x!=0), 4)] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[n.size()][0][K] + dp[n.size()][1][K] << endl;

  return 0;
}