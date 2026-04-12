#include <iostream>
 
int main()
{
  int X, Y, Z, result;
  std::cin >> X >> Y >> Z;

  result = (X - Z) / (Y + Z);
  
  std::cout << result;
  return 0;
}