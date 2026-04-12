#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <algorithm>

int main() {
  int N, K;
  std::cin >> N >> K;
  long long ans = 0;
  for (int b = K + 1; b <= N; ++b) {
    ans += (N / b) * (b - K);
    if (K) {
      ans += N % b >= K ? N % b - K + 1 : 0;
    } else {
      ans += N % b >= K ? N % b - K : 0;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}