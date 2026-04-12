#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  uint64_t A, B, C;
  int X, Y;
  std::cin >> A >> B >> C >> X >> Y;
  int diff = std::abs(X - Y);
  int common = std::min(X, Y);
  int cd = C * 2;
  int ab = A + B;
  

  if (cd <= ab) {
    int base = cd * common;
    if (X > Y && cd > A) {
      std::cout << base + diff * A << std::endl;
    } else if (Y > X && cd > B) {
      std::cout << base + diff * B << std::endl;
    } else {
      std::cout << base + diff * cd << std::endl;
    }
  } else {
    std::cout << A * X + B * Y << std::endl;
  }

  return 0;
}
