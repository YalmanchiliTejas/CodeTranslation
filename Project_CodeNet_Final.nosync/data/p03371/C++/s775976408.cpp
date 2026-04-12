#include <iostream>
#include <algorithm>

long long solve(int a, int b, int c, int x, int y) {
  const long long c1 { a * x + b * y };
  const long long c2 { 2 * c * std::min(x, y) + a * (x - std::min(x, y)) + b * (y - std::min(x, y)) };
  const long long c3 { 2 * std::max(x, y) * c };

  return std::min(c1, std::min(c2, c3));
}

int main() {
  int a, b, c, x, y;
  std::cin >> a >> b >> c >> x >> y;
  std::cout << solve(a, b, c, x, y) << std::endl;
  return 0;
}
