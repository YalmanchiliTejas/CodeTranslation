#include <bits/stdc++.h>

using namespace std;
using i64 = std::int_fast64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  int K;
  cin >> S >> K;
  int N = (int)S.size();
  vector<vector<vector<i64>>> dp(N + 1,
                                 vector<vector<i64>>(2, vector<i64>(K + 2, 0)));
  dp[0][0][0] = 1;
  for (int d = 0; d < N; d++) {
    for (int is_less = 0; is_less < 2; is_less++) {
      for (int k = 0; k < K + 1; k++) {
        int c = S[d] - '0';
        for (int nxt = 0; nxt < 10; nxt++) {
          if (c < nxt && is_less == 0) continue;

          int nis_less = is_less;
          if (nxt < c) nis_less = 1;

          int nk = k + (nxt == 0 ? 0 : 1);

          dp[d + 1][nis_less][nk] += dp[d][is_less][k];
        }
      }
    }
  }
  cout << dp[N][0][K] + dp[N][1][K] << '\n';
  return 0;
}
