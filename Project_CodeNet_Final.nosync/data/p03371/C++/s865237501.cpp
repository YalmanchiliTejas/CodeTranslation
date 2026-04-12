#include <bits/stdc++.h>

using namespace std;

int calc(int a, int b, int c, int x, int y) {
  int ret = a * x + b * y;
  for (int z = 2;; z += 2) {
    int const candidate =
        a * std::max(x - z / 2, 0) + b * std::max(y - z / 2, 0) + c * z;
    if (candidate >= ret) {
      break;
    }
    ret = candidate;
  }
  return ret;
}

int main() {
  int a, b, c, x, y;
  std::cin >> a >> b >> c >> x >> y;
  std::cout << calc(a, b, c, x, y) << std::endl;
  return 0;
}
