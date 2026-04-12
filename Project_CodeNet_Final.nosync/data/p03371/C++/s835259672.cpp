#include <iostream>

int main() {
  int a, b, c, x, y;
  std::cin >> a >> b >> c >> x >> y;
  int cost = 0;

  int greater_xy = std::max(x, y);
  int smaller_xy = std::min(x, y);

  // 小さい方に合わせるケース
  int smallercost = 0;
  if(x > y) {
    // yができる分購入する
    smallercost += 2*y*c;
    int sub = x - y;
    smallercost += a*sub;
  } else {
    smallercost += 2*x*c;
    int sub = y - x;
    smallercost += b*sub;
  }

  // 大きい方に合わせるケース
  int biggercost = 0;
  if(x > y) {
    biggercost += 2*x*c;
  } else {
    biggercost += 2*y*c;
  }


  int simplecost = a*x+b*y;
  cost = std::min(smallercost, biggercost);
  cost = std::min(cost, simplecost);

  std::cout << cost << std::endl;
  
}