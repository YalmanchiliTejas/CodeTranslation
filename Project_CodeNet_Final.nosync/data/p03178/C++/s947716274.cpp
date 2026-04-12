#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  int D;
  cin >> s >> D;
  
  ll dp[s.size() + 1][2][D + 2];
  for(int i = 0; i < s.size() + 1; i++){
    for(int j = 0; j < 2; j++){
      for(int ii = 0; ii < D + 2; ii++){
        dp[i][j][ii] = 0;
      }
    }
  }
  dp[0][0][0] = 1;
  
  for(int i = 0; i < s.size(); i++){
    for(int j = 0; j < 2; j++){
      for(int ii = 0; ii < D; ii++){
        for(int d = 0; d <= (j ? 9 : (int) s[i] - '0'); d++){
          dp[i + 1][j || (d < (int) s[i] - '0')][(ii + d) % D] += dp[i][j][ii];
          dp[i + 1][j || (d < (int) s[i] - '0')][(ii + d) % D] %= MOD;
        }
      }
    }
  }
  
  cout << (dp[s.size()][0][0] + dp[s.size()][1][0] - 1 + MOD) % MOD << '\n';
}