#include <iostream>
#include <cstdint>
#include <algorithm>

int const MAXN = 3000;

int N, a[MAXN];

int64_t dp[2][MAXN];

int main() {
  std::cin >> N;
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  for(int i = 0; i <=N; ++i) dp[0][i] = 0;
  for(int i = 1; i <=N; ++i) for(int j = 0; j+i<=N; ++j) {
    int k = j+i;
    dp[i%2][j] = std::max(a[k-1] - dp[(i-1)%2][j], a[j] - dp[(i-1)%2][j+1]);
  }
  std::cout << dp[N%2][0] << std::endl;
  return 0;
}
