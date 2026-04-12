#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define ll signed long long

int main() {
  int N;
  cin >> N;
  ll A[N];
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  ll dp[3][2][N];  // skip, used now, id
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < N; ++k) {
        dp[i][j][k] = -1 * (1ll << 60);
      }
    }
  }

  dp[1][0][0] = 0;
  dp[0][1][0] = A[0];
  for (int skip = 0; skip < 3; ++skip) {
    for (int i = 0; i < N; ++i) {
      for (int used = 0; used < 2; ++used) {
        if (used) {
          ll &m = dp[skip][used][i];
          if (i < 1) continue;
          m = max(m, dp[skip][0][i - 1] + A[i]);
          if (i < 2) continue;
          m = max(m, dp[skip][1][i - 2] + A[i]);

          if (skip < 1) continue;
          m = max(m, dp[skip - 1][0][i - 2] + A[i]);
          if (i < 3) continue;
          m = max(m, dp[skip - 1][1][i - 3] + A[i]);

          if (skip < 2) continue;
          m = max(m, dp[skip - 2][0][i - 3] + A[i]);
          if (i < 4) continue;
          m = max(m, dp[skip - 2][1][i - 4] + A[i]);
        } else {
          ll &m = dp[skip][used][i];
          if (i < 1) continue;
          m = max(m, dp[skip][1][i - 1]);

          if (skip < 1) continue;
          m = max(m, dp[skip - 1][0][i - 1]);
          if (i < 2) continue;
          m = max(m, dp[skip - 1][1][i - 2]);

          if (skip < 2) continue;
          m = max(m, dp[skip - 2][0][i - 2]);
          if (i < 3) continue;
          m = max(m, dp[skip - 2][1][i - 3]);
        }
      }
    }
  }

  ll ans = -(1ll << 60);
  if (N & 1) {
    ans = max(ans, dp[1][0][N - 1]);
    ans = max(ans, dp[2][1][N - 1]);
  } else {
    ans = max(ans, dp[0][0][N - 1]);
    ans = max(ans, dp[1][1][N - 1]);
  }

  // for (int i = 0; i < 3; ++i) {
  //   for (int j = 0; j < 2; ++j) {
  //     cout << i << " " << j << endl;
  //     for (int k = 0; k < N; ++k) {
  //       cout << dp[i][j][k] << " ";
  //     }
  //     cout << endl;
  //   }
  // }

  cout << ans << endl;

  return 0;
}
