#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

// dp[決めた桁数][N未満][0でない数字が何個あるか]
llint dp[111][2][5];

int main() {
  string s;
  int k, n;
  cin >> s >> k;
  n = s.size();
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    int num = s[i] - '0';
    for (int j = 0; j < 2; j++) {     // N未満かどうか
      for (int z = 0; z <= k; z++) {  // 0でない数字が何個あるか
        for (int d = 0; d <= (j ? 9 : num); d++) {
          dp[i + 1][j || (d < num)][z + (d > 0)] += dp[i][j][z];
        }
      }
    }
  }
  cout << dp[n][0][k] + dp[n][1][k] << endl;

  return 0;
}