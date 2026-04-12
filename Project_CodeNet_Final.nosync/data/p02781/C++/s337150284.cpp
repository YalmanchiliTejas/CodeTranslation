#include"bits/stdc++.h"
using namespace std;

int dp[105][4][2];

void Main() {
  string s;
  cin >> s;
  int n = s.size();
  int k;
  cin >> k;

  dp[0][0][0] = 1;
  for (int a = 0; a < n; a++) {
    for (int b = 0; b < 4; b++) {
      for (int c = 0; c < 2; c++) {
        int nd = s[a] - '0';
        for (int d = 0; d < 10; d++) {
          int na = a + 1, nb = b, nc = c;
          if (d != 0) nb++;
          if (nb > k) continue;
          if (c == 0) {
            if (d > nd) continue;
            if (d < nd) nc = 1;
          }
          dp[na][nb][nc] += dp[a][b][c];
        }
      }
    }
  }

  int ans = dp[n][k][0] + dp[n][k][1];
  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}
