#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


int
main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> matrix;
  for (int i = 0; i < h; i++) {
    std::string s;
    std::cin >> s;
    if (s.find('#') != std::string::npos) {
      matrix.push_back(std::move(s));
    }
  }

  for (int i = w - 1; i != -1; i--) {
    auto isIgnore = true;
    for (int j = 0, jm = static_cast<int>(matrix.size()); j < jm; j++) {
      if (matrix[j][i] == '#') {
        isIgnore = false;
        break;
      }
    }
    if (isIgnore) {
      for (int j = 0, jm = static_cast<int>(matrix.size()); j < jm; j++) {
        matrix[j].erase(i, 1);
      }
    }
  }

  for (const auto& row : matrix) {
    std::cout << row << std::endl;
  }

  return EXIT_SUCCESS;
}
