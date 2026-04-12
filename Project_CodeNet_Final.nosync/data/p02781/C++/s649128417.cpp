#include <bits/stdc++.h>

#define rep(i, n) for(int (i) = 0; i < (n); ++(i))

using ll = long long int;
const ll MOD = 1e9 + 7;

int main() {
  std::string N_str;
  int K;
  std::cin >> N_str >> K;

  std::vector<int> N(N_str.size());
  rep(i, N_str.size()) {
    N[i] = N_str[i] - '0';
  }


  int n = N.size();
  std::vector<std::vector<std::vector<int>>> dp(2,
    std::vector<std::vector<int>>(n + 1,
      std::vector<int>(K + 1))
  );
  dp[0][0][0] = 1;

  rep(i, n) {
    rep(j, K + 1) {
      rep(k, 2) {
        rep(d, 10) {
          int ni = i + 1, nj = j, nk = k;
          if(d != 0) ++nj;
          if(nj > K) continue;
          if(k == 0) {
            if(d > N[i]) continue;
            if(d < N[i]) nk = 1;
          }
          dp[nk][ni][nj] += dp[k][i][j];
        }
      }
    }
  }

  std::cout << dp[0][n][K] + dp[1][n][K] << '\n';
}
