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
#define DEBUG 1
constexpr int kMod = 1000000007;
typedef long long LL;

LL dp[10001][2][101];  // keta, smaller, D

int main() {
  std::string N; std::cin >> N;
  int D; std::cin >> D;
  size_t length = N.length();

  // Initialize.
  for (size_t i = 0; i <= length; ++i) {
    for (int s = 0; s < 2; ++s) {
      for (int d = 0; d <= D; ++d) {
        dp[i][s][d] = 0;
      }
    }
  }

  dp[0][0][0] = 1;
  for (int i = 1; i <= length; ++i) {
    int v = N[i-1] - '0';
    for (int d = 0; d < D; ++d) {
      for (int n = 0; n < 10; ++n) {
        if (n < v) {
          dp[i][1][(d + n) % D] += dp[i-1][0][d] + dp[i-1][1][d];
        } else if (n == v) {
          dp[i][0][(d + n) % D] += dp[i-1][0][d];
          dp[i][1][(d + n) % D] += dp[i-1][1][d];
        } else { // n < v
          dp[i][1][(d + n) % D] += dp[i-1][1][d];
        }

        dp[i][0][(d + n)%D] %= kMod;
        dp[i][1][(d + n)%D] %= kMod;
      }
    }
  }

  std::cout << (dp[length][0][0] + dp[length][1][0] - 1 + kMod) % kMod << std::endl;
}
