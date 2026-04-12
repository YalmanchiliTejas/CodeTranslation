#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  int N, K;
  cin >> S >> K;
  N = (int)S.size();
  vector<vector<vector<int>>> dp(N + 1,
                                 vector<vector<int>>(2, vector<int>(K + 1, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      int c = S[i] - '0';
      for (int n = 0; n < 10; n++) {
        if (c < n && j == 0) continue;
        for (int k = 0; k < K + 1; k++) {
          int nj = j;
          if (c > n) nj = 1;

          int nk = k;
          if (n != 0) nk++;

          dp[i + 1][nj][nk] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[N][0][K] + dp[N][1][K] << '\n';
  return 0;
}
