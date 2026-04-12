
#include <bits/stdc++.h>

int main() {
  int64_t a, b, c, x, y;
  std::cin >> a >> b >> c >> x >> y;

  int64_t price = 0;

  if (c * 2 < a + b) {
    const auto n = std::min(x, y);
    price += c * 2 * n;
    x -= n;
    y -= n;
  }
  if (c * 2 < a) {
    price += c * 2 * x;
    y -= x;
    y = std::max(static_cast<int64_t>(0), y);
    x = 0;
  }
  if (c * 2 < b) {
    price += c * 2 * y;
    x -= y;
    x = std::max(static_cast<int64_t>(0), x);
    y = 0;
  }

  price += a * x + b * y;

  std::cout << price << std::endl;
  return 0;
}
