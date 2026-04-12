#include <cstdlib>
#include <iostream>


int
main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int r, g, b;
  std::cin >> r >> g >> b;

  std::cout << ((r * 100 + g * 10 + b) % 4 == 0 ? "YES" : "NO") << std::endl;

  return EXIT_SUCCESS;
}
