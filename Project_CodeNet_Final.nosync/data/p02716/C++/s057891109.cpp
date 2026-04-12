#include<iostream>
#include<cstdint>
#include<algorithm>

int64_t const INF = 1e15;
int const MAXN = 2e5;

int64_t dp[MAXN+3][2], A[MAXN];

int main() {
  int N; std::cin >> N;
  for(int i = 0; i < N; ++i) std::cin >> A[i];
  std::fill_n(dp[0], MAXN*2, -INF);
  dp[0][1] = A[0];
  dp[1][0] = A[1];
  dp[2][0] = A[2];
  for(int i = 0; i+2 < N; ++i) {
    // i => i+2
    dp[i+2][0] = std::max(dp[i+2][0], dp[i][0] + A[i+2]);
    dp[i+2][1] = std::max(dp[i+2][1], dp[i][1] + A[i+2]);
    if(i%2) {
      // i => i+3
      dp[i+3][0] = std::max(dp[i+3][0], dp[i][0] + A[i+3]);
    } else {
      // i => i+3, i+4
      dp[i+3][0] = std::max(dp[i+3][0], dp[i][1] + A[i+3]);
      dp[i+4][0] = std::max(dp[i+4][0], dp[i][1] + A[i+4]);
    }
  }
  int64_t ans;
  if(N%2) ans = std::max(dp[N-3][1], std::max(dp[N-1][0], dp[N-2][0]));
  else ans = std::max(dp[N-1][0], dp[N-2][1]);
  std::cout << ans << std::endl;
  return 0;
}
