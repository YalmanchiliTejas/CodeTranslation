#include <iostream>

int main() {
  long long a, b, c, x, y;
  long long sum = 0;
  std::cin >> a >> b >> c >> x >> y;
  if (a + b < c * 2) {
    std::cout << a * x + b * y << "\n";
    return 0;
  } else {
    if (x < y) {
      sum += c * x * 2;
      y -= x;
      if (b < c * 2) {
        sum += b * y;
      } else {
        sum += c * y * 2;
      }
    } else {
      sum += c * y * 2;
      x -= y;
      if (a < c * 2) {
        sum += a * x;
      } else {
        sum += c * x * 2;
      }
    }
  }
  std::cout << sum << "\n";
  return 0;
}