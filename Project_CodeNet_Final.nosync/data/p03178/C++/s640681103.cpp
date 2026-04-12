#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
typedef long long LL;
constexpr int kMod = 1000000007;

LL dp[10000][101][2] = {};  // idx, sum%D, less/tight

int main() {
  std::string S; std::cin >> S;
  int D; std::cin >> D;

  dp[0][0][0] = 1;
  for (size_t idx = 0; idx < S.length(); ++idx) {
    int c = S[idx] - '0';
    for (int sum = 0; sum < D; ++sum) {
      for (int less : {0, 1}) {
        for (int n = 0; n < 10; ++n) {
          if (n<c)         dp[idx+1][(sum + n) % D][1] += dp[idx][sum][less];
          else if (n == c) dp[idx+1][(sum + n) % D][less] += dp[idx][sum][less];
          else if (less)   dp[idx+1][(sum + n) % D][less] += dp[idx][sum][less];

          dp[idx+1][(sum + n) % D][0] %= kMod;
          dp[idx+1][(sum + n) % D][1] %= kMod;
        }
      }
    }
  }

  std::cout
    << (dp[S.length()][0][0] + dp[S.length()][0][1] + kMod - 1) % kMod << std::endl;
}
