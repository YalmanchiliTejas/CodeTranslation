#include <iostream>
#include <string>

int main()
{
  int X;
  std::cin >> X;

  std::string judge = (X == 3 || X == 5 || X == 7) ? "YES" : "NO";
  std::cout << judge << std::endl;
  
  return 0;
}
