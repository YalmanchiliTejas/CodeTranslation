#include <bits/stdc++.h>
int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  auto cal = [&] (long long n, long long k, long long b) {
    assert(k < b);
    return
      n / b * (b - k) +
      std::max(0LL, n % b - k + 1);
  };
  long long n, k; std::cin >> n >> k;
  if (k == 0) {
    std::cout << n * n << std::endl;
    return 0;
  }
  long long ans = 0;
  for (int b = k + 1; b <= n; b++) {
    ans += cal(n, k, b);
  }
  std::cout << ans << std::endl;
  return 0;
}