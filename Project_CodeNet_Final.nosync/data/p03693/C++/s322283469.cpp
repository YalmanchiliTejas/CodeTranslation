#include <bits/stdc++.h>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if ((a * 100 + b * 10 + c) % 4 == 0) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
