#include <iostream>
#include <vector>

template <class T> inline bool chmax(T &a, const T &b) {
  return (a < b) ? a = b, true : false;
}

int main() {
  int N;
  std::cin >> N;
  std::vector<long long> a(N);
  for (int i = 0; i < N; ++i)
    std::cin >> a[i];

  long long inf = 1LL << 60;
  std::vector<std::vector<long long>> dp(N + 7,
                                         std::vector<long long>(N + 7, -inf));
  for (int i = 0; i <= N; ++i)
    dp[i][i] = 0;
  for (int k = 0; k <= N; ++k) {
    for (int i = 0; i <= N - k; ++i) {
      int j = i + k;
      chmax(dp[i][j + 1], a[j] - dp[i][j]);
      if (i > 0)
        chmax(dp[i - 1][j], a[i - 1] - dp[i][j]);
    }
  }
  std::cout << dp[0][N] << std::endl;
}
