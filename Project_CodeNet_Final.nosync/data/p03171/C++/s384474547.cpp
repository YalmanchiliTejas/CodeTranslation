#include <iostream>
#include <vector>
typedef long long LL;
constexpr int kMax = 3000;

int main() {
  LL dp[kMax][kMax] = {};
  int N; std::cin >> N;

  for (int i = 0; i < N; ++i) {
    std::cin >> dp[i][i];
  }

  for (int j = 1; j < N; ++j) {
    for (int i = 0; i < N - j; ++i) {
      dp[i][i+j] = std::max(dp[i][i]-dp[i+1][i+j], dp[i+j][i+j] - dp[i][i+j-1]);
    }
  }

  std::cout << dp[0][N-1] << std::endl;
}
