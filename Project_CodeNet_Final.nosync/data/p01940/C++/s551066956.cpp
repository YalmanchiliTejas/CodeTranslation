#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using usize = std::size_t;
using u64 = std::uint64_t;

static constexpr u64 mod = 1000000007;

int main() {
  std::string t, p;
  std::cin >> t >> p;
  const usize n = t.size();

  bool flag = true;

  const auto match = [&]() {
    std::vector<bool> v(n, false);
    usize i = 0;
    for (const auto c : p) {
      while (i != n && t[i] != c) {
        i += 1;
      }
      if (i == n) {
        flag = false;
        break;
      }
      v[i] = true;
      i += 1;
    }
    return std::move(v);
  };

  auto f = match();
  if (!flag) {
    std::cout << "no\n";
    return 0;
  }
  std::reverse(t.begin(), t.end());
  std::reverse(p.begin(), p.end());
  auto b = match();
  std::reverse(b.begin(), b.end());

  for (usize i = 0; i != n; ++i) {
    if (f[i] != b[i]) {
      std::cout << "no\n";
      return 0;
    }
  }
  std::cout << "yes\n";

  return 0;
}
