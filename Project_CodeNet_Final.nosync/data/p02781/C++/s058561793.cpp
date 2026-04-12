#include <algorithm>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 0
constexpr int kMod = 1000000007;
typedef long long LL;

LL dp[101][2][5];  // keta, smaller, K

int main() {
  std::string N; std::cin >> N;
  int K; std::cin >> K;
  int length = N.length();

  // Initialize.
  for (int i = 0; i <= length; ++i) {
    for (int s = 0; s < 2; ++s) {
      for (int k = 0; k <= K; ++k) {
        dp[i][s][k] = 0;
      }
    }
  }

  dp[0][0][0] = 1;
  for (int i = 1; i <= length; ++i) {
    LL v = N[i-1] - '0';
    for (int k = 0; k <= K; ++k) {
      if (v == 0) {
        dp[i][0][k] += dp[i-1][0][k];
        dp[i][1][k+1] += 9 * dp[i-1][1][k];
        dp[i][1][k] += dp[i-1][1][k];
      } else {  // v != 0
        dp[i][0][k+1] += dp[i-1][0][k];
        dp[i][1][k+1] += 9 * dp[i-1][1][k] + (v-1) * dp[i-1][0][k];
        dp[i][1][k] += dp[i-1][1][k] + dp[i-1][0][k];
      }
    }
  }

#if DEBUG
  for (int i = 0; i <= length; ++i) {
    for (int s = 0; s < 2; ++s) {
      for (int k = 0; k <= K; ++k) {
        std::cout << dp[i][s][k] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << "-----" << std::endl;
  }
#endif

  std::cout << (dp[length][0][K] + dp[length][1][K]) << std::endl;
}
