#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> hs(n);
  for (auto&& h : hs) std::cin >> h;

  int m = 0;
  int hmax = hs[0];
  for (auto&& h : hs) {
    if (hmax <= h) {
      hmax = h;
      ++m;
    }
  }
  std::cout << m << std::endl;
}
