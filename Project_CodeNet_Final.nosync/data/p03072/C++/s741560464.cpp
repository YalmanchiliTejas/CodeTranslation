#include <bits/stdc++.h>

using namespace std;

int64_t solve(int64_t n, std::vector<int64_t> hs) {
  int64_t ret = 1;
  int64_t maximum = hs[0];
  for ( int i = 1; i < n; ++i) {
    if (hs[i] >= maximum) {
      ret ++;
    }
    maximum = std::max(hs[i],  maximum);
  }
  return ret;
}

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int64_t n;
  std::cin >> n;
  std::vector<int64_t> hs(n);
  for (int i = 0; i < n; i++) {
    std::cin >> hs[i];
  }
  auto const res = solve(n, std::move(hs));
  std::cout << res << std::endl;
  return 0;
}
