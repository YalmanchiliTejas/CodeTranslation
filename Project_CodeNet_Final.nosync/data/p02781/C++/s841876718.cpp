#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string N;
  int K;
  cin >> N >> K;
  vector<vector<vector<int>>> dp(N.size() + 1,
                                 vector<vector<int>>(2, vector<int>(10, 0)));
  dp[0][0][0] = 1;
  // dp[i][smaller][digits]
  for (int i = 0; i < (int)N.size(); i++) {
    for (int s = 0; s < 2; s++) {
      for (int k = 0; k < K + 1; k++) {
        int c = N[i] - '0';

        for (int n = 0; n < 10; n++) {
          if (n > c && s == 0) continue;
          int ns = s;
          if (n < c) ns = 1;
          int nk = k;
          if (n != 0) nk++;

          dp[i + 1][ns][nk] += dp[i][s][k];
        }
      }
    }
  }
  cout << dp[N.size()][0][K] + dp[N.size()][1][K] << '\n';
  return 0;
}
