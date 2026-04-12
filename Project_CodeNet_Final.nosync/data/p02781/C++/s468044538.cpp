#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

int dp[101][2][5] = {};

int main() {
  std::string N;
  int K;
  std::cin >> N >> K;
  int L = N.size();
  dp[0][0][0] = 1;
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k <= K; ++k) {
        const int D = j ? 9 : N[i] - '0';
        for (int d = 0; d <= D; ++d) {
          dp[i+1][j || (d < D)][k + (d != 0)] += dp[i][j][k];
        }
      }
    }
  }
  std::cout << dp[L][0][K] + dp[L][1][K] << std::endl;
  return 0;
}
