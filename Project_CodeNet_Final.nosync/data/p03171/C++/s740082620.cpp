#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstring>

int N;
int64_t a[3001];
int64_t dp[3001][3001];

int main() {
  std::cin >> N;
  for (int i = 0; i < N; ++i)
    std::cin >> a[i];
  for (int i = 0; i < N; ++i) {
    for (int j = i; j >= 0; --j) {
      if (i == j) {
        dp[j][i] = a[i];
      } else {
        dp[j][i] = std::max(a[j] - dp[j+1][i], a[i] - dp[j][i-1]);
      }
    }
  }
  std::cout << dp[0][N-1] << '\n';
}
