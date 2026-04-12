#include <bits/stdc++.h>
int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::vector<int> now;
  for (auto x : a) {
    auto ub = std::upper_bound(now.begin(), now.end(), x, std::greater<int>{});
    if (ub != now.end()) {
      *ub = x;
    } else {
      now.push_back(x);
    }
  }
  std::cout << now.size() << std::endl;
  return 0;
}