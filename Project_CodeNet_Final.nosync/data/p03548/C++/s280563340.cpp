#include <iostream>

int main(int argc, char* argv[])
{
  int x, y, z;
  std::cin >> x >> y >> z;

  std::cout << (x - z) / (y + z) << std::endl;
  return 0;
}
