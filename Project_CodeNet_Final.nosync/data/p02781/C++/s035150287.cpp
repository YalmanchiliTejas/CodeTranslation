#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  int K;
  cin >> S >> K;
  vector<vector<vector<int>>> dp(S.size() + 1,
                                 vector<vector<int>>(2, vector<int>(K + 2, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < (int)S.size(); i++) {
    int c = S[i] - '0';
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < K + 1; k++) {
        for (int nc = 0; nc < 10; nc++) {
          if (nc > c && j == 0) continue;
          int nj = nc < c ? 1 : j;
          int nk = nc != 0 ? k + 1 : k;
          dp[i + 1][nj][nk] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[S.size()][0][K] + dp[S.size()][1][K] << '\n';
  return 0;
}
