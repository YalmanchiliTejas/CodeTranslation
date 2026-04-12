#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  string Ns; cin>>Ns;
  int K; cin>>K;
  size_t dp[Ns.size()][11][K+1];
  memset(dp, 0, sizeof(size_t)*(Ns.size())*11*(K+1));
  auto ctoi = [](char c) {return c - '0';};
  dp[0][0][0] = 1;
  for (int i = 1; i < ctoi(Ns[0]); i++) {
    dp[0][i][1] = 1;
  }
  dp[0][10][1] = 1;
  for (size_t i = 1; i < Ns.size(); i++) {
    auto th = ctoi(Ns[i]);
    for (int z = 0; z <= K; z++) {
      for (int j = 0; j <= 9; j++) {
        dp[i][0][z] += dp[i-1][j][z];
        if (z < K) {
          for (int n = 1; n <= 9; n++) {
            dp[i][n][z+1] += dp[i-1][j][z];
          }
        }
      }
      // from edge
      if (th == 0) {
        dp[i][10][z] += dp[i-1][10][z];
      } else {
        dp[i][0][z] += dp[i-1][10][z];
        if (z < K) {
          for (int n = 1; n < th; n++) {
            dp[i][n][z+1] += dp[i-1][10][z];
          }
          dp[i][10][z+1] += dp[i-1][10][z];
        }
      }
    }
  }
  size_t ans = 0;
  for (int i = 0; i <= 10; i++) {
    ans += dp[Ns.size()-1][i][K];
  }
  cout << ans << endl;

  return 0;
}
