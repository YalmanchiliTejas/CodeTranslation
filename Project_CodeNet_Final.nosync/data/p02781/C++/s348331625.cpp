#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using namespace std;


void solve(string N, long long K){
  vector<vector<vector<long long>>> dp(N.size(), vector<vector<long long>>(K+1, vector<long long>(2, 0)));
  dp[0][0][0] = 1LL;
  dp[0][1][0] = static_cast<long long>(N[0] - '1');
  dp[0][1][1] = 1LL;
  for (int i = 1; i < N.size(); ++i) {
    for (int j = 0; j < K+1; ++j) {
      if (N[i] == '0') {
        dp[i][j][1] += dp[i-1][j][1];
      } else if (j > 0) {
        dp[i][j][1] += dp[i-1][j-1][1];
      }

      if (N[i] != '0') {
        dp[i][j][0] += dp[i-1][j][1];
      }

      dp[i][j][0] += dp[i-1][j][0];

      if (N[i] != '0' and j > 0) {
        dp[i][j][0] += dp[i-1][j-1][1] * static_cast<long long>(N[i] - '1');
      }

      if (j > 0) {
        dp[i][j][0] += dp[i-1][j-1][0] * 9LL;
      }
    }
  }
  std::cout << dp[N.size()-1][K][0] + dp[N.size()-1][K][1] << std::endl;
}

int main(){
  string N;
  std::cin >> N;
  long long K;
  scanf("%lld",&K);
  solve(N, K);
  return 0;
}
