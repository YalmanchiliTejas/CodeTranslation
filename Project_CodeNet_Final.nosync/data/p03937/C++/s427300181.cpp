#include <iostream>
#include <vector>

int main() {
  unsigned H, W;
  std::cin >> H >> W;
  std::vector<std::vector<char>> a(H, std::vector<char>(W));
  for (unsigned i = 0; i < H; ++i) {
    for (unsigned j = 0; j < W; ++j) {
      std::cin >> a[i][j];
    }
  }
  std::vector<unsigned> max(H, 0);
  std::vector<unsigned> min(H, UINT32_MAX);
  for (unsigned i = 0; i < H; ++i) {
    for (unsigned j = 0; j < W; ++j) {
      if (a[i][j] == '#') {
        max[i] = j;
        if (min[i] > j) {
          min[i] = j;
        }
      }
    }
  }
  for (unsigned i = 0; i < H - 1; ++i) {
    if (max[i] != min[i + 1]) {
      std::cout << "Impossible";
      return 0;
    }
  }
  std::cout << "Possible";
  return 0;
}