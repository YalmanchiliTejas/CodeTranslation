#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string n;
  int k;
  std::cin >> n >> k;
  int len = n.size();

  std::vector<int[5][2]> dp(len + 1); // dp[何文字目][非 0 何個][n より小か]
  dp[0][0][0] = 1;
  for (int i = 0; i < len; i += 1) { // 何文字目
    int d = n[i] - '0';              // i 文字目の数字

    // 配るDP
    for (int j = 0; j <= k; j += 1) {     // 非 0 何個
      for (int s = 0; s <= 1; s += 1) {   // n より小か
        for (int c = 0; c <= 9; c += 1) { // 遷移に使う数字
          if (!s && c > d) // n を超過する場合遷移しない
            continue;
          dp[i + 1][j + (c != 0)][s || (c < d)] += dp[i][j][s];
        }
      }
    }
  }

  std::cout << dp[len][k][0] + dp[len][k][1] << std::endl;
}