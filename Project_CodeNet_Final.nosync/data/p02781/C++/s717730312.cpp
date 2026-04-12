#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  int K;
  cin >> S >> K;
  int N = S.length();
  if (N < K) {
    cout << 0 << endl;
    return 0;
  }
  vector<vector<long long>> dp0(N + 1, vector<long long>(5));
  vector<vector<long long>> dp1(N + 1, vector<long long>(5));
  dp1[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++) {
      dp0[i + 1][j] += dp0[i][j];
      dp0[i + 1][j + 1] += dp0[i][j] * 9;
      int d = S[i] - '0';
      if (d == 0) {
        dp1[i + 1][j] += dp1[i][j];
      } else {
        dp1[i + 1][j + 1] += dp1[i][j];
        dp0[i + 1][j] += dp1[i][j];
        dp0[i + 1][j + 1] += dp1[i][j] * (d - 1);
      }
    }
  }
  long long ans = dp0[N][K] + dp1[N][K];
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
