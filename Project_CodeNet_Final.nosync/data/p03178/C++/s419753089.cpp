#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string k;
  int d;
  cin >> k >> d;
  
  ll dp[k.size() + 1][2][d];
  for (int i = 0; i < k.size() + 1; i++) {
    for (int j = 0; j < 2; j++) {
      for (int ii = 0; ii < d; ii++) {
        dp[i][j][ii] = 0;
      }
    }
  }
  dp[0][0][0] = 1;
  
  for (int i = 0; i < k.size(); i++) {
    for (int j = 0; j < 2; j++) {
      for (int ii = 0; ii < d; ii++) {
        for (int next = 0; next <= (j ? 9 : k[i] - '0'); next++) {
          dp[i + 1][j | (next < k[i] - '0')][(ii + next) % d] += dp[i][j][ii];
          dp[i + 1][j | (next < k[i] - '0')][(ii + next) % d] %= MOD;
        }
      }
    }
  }
  
  cout << (dp[k.size()][0][0] + dp[k.size()][1][0] - 1 + MOD) % MOD << '\n';
}