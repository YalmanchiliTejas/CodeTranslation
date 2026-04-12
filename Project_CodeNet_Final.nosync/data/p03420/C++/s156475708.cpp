/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, K;
  cin >> N >> K;
  if (N <= K) {
    cout << 0 << endl;
    return 0;
  }
  int64_t result = 0;
  for (int64_t b = 1; b <= N; ++b) {
    const int64_t p = N / b;
    const int64_t r = N % b;
    int64_t temp = p * max(b - K, 0L) + max(r - K + 1, 0L);
    if (K == 0) {
      --temp;
    }
    result += temp;
  }
  cout << result << endl;
  return 0;
}
