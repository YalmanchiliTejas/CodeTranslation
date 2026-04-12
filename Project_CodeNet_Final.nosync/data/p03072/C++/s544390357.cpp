#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> Hs(N);
  for (auto&& H : Hs) std::cin >> H;

  int ans = 0;
  int Hmax = Hs[0];
  for (auto&& H : Hs) {
    if (Hmax <= H) {
      ++ans;
      Hmax = H;
    }
  }
  std::cout << ans << std::endl;
}
