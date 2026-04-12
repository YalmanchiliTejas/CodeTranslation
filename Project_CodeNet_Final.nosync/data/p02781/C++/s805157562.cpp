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
typedef long long LL;

LL dp1[102][5];  // tight dp, keta, K
LL dp2[102][5];  // less  dp, keta, K

int main() {
  std::string N; std::cin >> N;
  int K; std::cin >> K;
  int length = static_cast<int>(N.length());

  // Zero Initialize.
  for (int i = 0; i <= length; ++i) {
    for (int k = 0; k <= K; ++k) {
      dp1[i][k] = 0; dp2[i][k] = 0;
    }
  }

  dp1[0][0] = 1;
  for (int i = 1; i <= length; ++i) {
    int v = N[i-1] - '0';
    for (int k = 0; k <= K; ++k) {
      if (v == 0) {
        dp1[i][k] += dp1[i-1][k];
        dp2[i][k + 1] += 9 * dp2[i-1][k];  // Select 1-9
        dp2[i][k] += dp2[i-1][k];          // Select 0
      } else {
        dp1[i][k + 1] += dp1[i-1][k];
        dp2[i][k + 1] += 9 * dp2[i-1][k] + (v-1) * dp1[i-1][k]; // Select 1-9
        dp2[i][k] += dp2[i-1][k] + dp1[i-1][k];                 // Select 0
      }
    }
#if DEBUG
    std::cout << "t: ";
    for (int k = 0; k <= K; ++k) {
      std::cout << dp1[i][k] << " ";
    }
    std::cout << std::endl;
    std::cout << "l: ";
    for (int k = 0; k <= K; ++k) {
      std::cout << dp2[i][k] << " ";
    }
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
#endif
  }

  std::cout << dp1[length][K] + dp2[length][K] << std::endl;
}
