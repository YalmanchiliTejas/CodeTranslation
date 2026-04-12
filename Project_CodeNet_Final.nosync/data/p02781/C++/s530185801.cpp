#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  int K;
  cin >> S >> K;
  int N = (int)S.size();
  vector<vector<vector<int>>> dp(N + 1,
                                 vector<vector<int>>(2, vector<int>(K + 2, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    int c = S[i] - '0';
    for (int j = 0; j < 2; j++) {
      for (int nc = 0; nc < 10; nc++) {
        if (nc > c && j == 0) continue;
        for (int k = 0; k < K + 1; k++) {
          int nj = j;
          if (nc < c) nj = 1;
          int nk = k;
          if (nc != 0) nk++;
          dp[i + 1][nj][nk] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[N][0][K] + dp[N][1][K] << '\n';
  return 0;
}
