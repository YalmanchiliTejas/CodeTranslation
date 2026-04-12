#include <iostream>

int main(void) {
  int a, b, c, x, y;
  int cost=0, tmp;
  double ha, hb;
  std::cin >> a >> b >> c >> x >> y;
  ha = (double) a / (double) 2;
  hb = (double) b / (double) 2;
  if (ha + hb > c) {
    if (x > y) {
      tmp = y;
      x = x - y;
      y = 0;
    } else {
      tmp = x;
      y = y - x;
      x = 0;
    }

    cost = 2 * tmp * c;
    if (x*a+y*b < c * 2 * (x+y)) {
      cost += a * x + b * y;
    } else {
      cost += 2 * c * (x+y);
    }

  } else {
    cost = (x*a) + (y*b);
  }
  std::cout << cost << std::endl;
  return 0;
}
