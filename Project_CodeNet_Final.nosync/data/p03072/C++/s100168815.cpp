#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> h(n);

  for (auto &i : h) {
    std::cin >> i;
  }

  int ans = 0;
  for (auto itr = h.cbegin(); itr != h.cend(); itr++) {
    if (*std::max_element(h.cbegin(), itr) <= *itr) {
      ans++;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
