#include <bits/stdc++.h>

int main() {
  int64_t A, B, C, X, Y;
  std::cin >> A >> B >> C >> X >> Y;
  if ((A + B) <= 2 * C) {
    std::cout << A * X + B * Y << std::endl;
  } else if (X > Y) {
    std::cout << std::min(A, 2 * C) * (X - Y) + 2 * C * Y << std::endl;
  } else {
    std::cout << 2 * C * X + std::min(B, 2 * C) * (Y - X) << std::endl;
  }
    return 0;
}