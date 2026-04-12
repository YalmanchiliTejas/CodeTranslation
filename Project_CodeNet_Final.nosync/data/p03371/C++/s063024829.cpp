/**
  *  Worg
  */
#include <iostream>
#include <algorithm>

int main() {
  int a, b, c, x, y;
  std::cin >> a >> b >> c >> x >> y;

  int answer = 0;

  //  Vedem cate cumparam la pachet
  if (c * 2 < a + b) {
    int d = std::min(x, y);

    answer += d * (c * 2);

    x -= d; y -= d;
  }

  //  Ne ocupam de A-urile ramase
  if (x >= 0) {
    if (c * 2 < a) {
      answer += x * (c * 2);
    } else {
      answer += x * a;
    }
  }

  //  Ne ocupam de B-urile ramase
  if (y >= 0) {
    if (c * 2 < b) {
      answer += y * (c * 2);
    } else {
      answer += y * b;
    }
  }

  std::cout << answer << '\n';
  return 0;
}
