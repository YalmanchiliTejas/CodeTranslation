#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  uint32_t A, B, C;
  int64_t X, Y;
  std::cin >> A >> B >> C >> X >> Y;

  int64_t M = std::max(X, Y);
  int64_t ret = 0;

  if (C * 2 < (A + B)) {
    ret = (C * 2) * (M - std::abs(X - Y));
    
    if (X > Y) {
      if (C * 2 > A) {
        ret += A * (X - Y);
      } else {
        ret += (C * 2) * (X - Y);
      }
    } else if (Y > X) {
      if (C * 2 > B) {
        ret += B * (Y - X);
      } else {
        ret += (C * 2) * (Y - X);
      }
    }
  } else {
    ret = (A * X) + (B * Y);
  }

  std::cout << ret << std::endl;

  return 0;
}
