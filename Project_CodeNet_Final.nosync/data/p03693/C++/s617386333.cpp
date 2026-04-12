#include <iostream>

int main()
{
  int r, g, b;
  std::cin >> r >> g >> b;
  bool is_multi_4 = (10 * g + b) % 4 == 0;

  std::cout << (is_multi_4 ? "YES" : "NO") << std::endl;

  return 0;
}
