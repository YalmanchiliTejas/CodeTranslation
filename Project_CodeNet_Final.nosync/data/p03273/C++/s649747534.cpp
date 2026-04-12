#include <iostream>

void print_grid(int x, int y, std::string grid[])
{
  for (auto i = 0; i < y; ++i) {
    auto c = 0;
    for (auto j = 0; j < x; ++j) {
      if (grid[i][j] == 'n') {
        ++c;
        continue;
      }
      std::cout << grid[i][j];
    }
    if (x != c)
      std::cout << std::endl;
  }
}

int main()
{
  // input grid
  int x, y;
  std::cin >> y >> x;
  std::string in_grid[y];
  std::string out_grid[y];
  for (auto i = 0; i < y; ++i) {
    std::cin >> in_grid[i];
    out_grid[i] = in_grid[i];
  }
  // check grid row
  for (auto i = 0; i < x; ++i) {
    for (auto j = 0; j < y; ++j) {
      if ('.' != in_grid[j][i]) break;
      if (j == y-1) {
        for (auto k = 0; k < y; ++k) {
          out_grid[k][i] = 'n';
        }
      }
    }
  }
  // check grid column
  for (auto i = 0; i < y; ++i) {
    for (auto j = 0; j < x; ++j) {
      if ('.' != in_grid[i][j]) break;
      if (j == x-1) {
        for (auto k = 0; k < x; ++k)
          out_grid[i][k] = 'n';
      }
    }
  }
  print_grid(x, y, out_grid);
  return 0;
}