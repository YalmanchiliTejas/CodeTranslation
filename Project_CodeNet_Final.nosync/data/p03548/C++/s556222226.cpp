#include <iostream>

int main()
{
  unsigned X, Y, Z;
  std::cin >> X >> Y >> Z;
  unsigned N = (X - (Y + 2 * Z)) / (Y + Z);
  std::cout << (N + 1) << std::endl;
  return 0;
}