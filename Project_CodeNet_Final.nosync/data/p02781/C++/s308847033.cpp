#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int l = s.size();
  vector<int> n(l);
  for(int i = 0; i < l; i++) n.at(i) = s.at(i) - '0';
  
  int dp[110][2][110];
  dp[0][0][0] = 1;
  for(int i = 0; i < l; i++){
    for(int sma = 0; sma < 2; sma++){
      for(int j = 0; j <= k; j++){
        for(int x = 0; x <=(sma ? 9: n.at(i)); x++){
          if(x == 0) dp[i+1][sma || x < n.at(i)][j] += dp[i][sma][j];
          else dp[i+1][sma || x < n.at(i)][j+1] += dp[i][sma][j];
        }
      }
    }
  }
  
  cout << dp[l][0][k] + dp[l][1][k] << endl;
  
}