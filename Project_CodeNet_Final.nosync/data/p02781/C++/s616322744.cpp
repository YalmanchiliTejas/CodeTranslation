#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  int k;
  cin >> s >> k;
  
  ll dp[s.size() + 1][2][k + 2];
  for(int i = 0; i < s.size() + 1; i++){
    for(int j = 0; j < 2; j++){
      for(int ii = 0; ii < k + 1; ii++){
        dp[i][j][ii] = 0;
      }
    }
  }
  dp[0][0][0] = 1;
  
  for(int i = 0; i < s.size(); i++){
    for(int j = 0; j < 2; j++){
      for(int ii = 0; ii < k + 1; ii++){
        for(int d = 0; d <= (j ? 9 : (int) s[i] - '0'); d++){
          dp[i + 1][j || (d < (int) s[i] - '0')][ii + (d != 0)] += dp[i][j][ii];
        }
      }
    }
  }
  
  cout << dp[s.size()][0][k] + dp[s.size()][1][k] << '\n';
}