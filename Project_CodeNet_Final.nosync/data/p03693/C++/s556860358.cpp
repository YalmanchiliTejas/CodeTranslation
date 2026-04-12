#include <iostream>
#include <string>

int main()
{
  std::string r, g, b;
  std::cin >> r >> g >> b;
  int num = std::stoi(r + g + b);
  if ( num % 4 == 0 ) std::cout << "YES\n";
  else std::cout << "NO\n";

  return 0;
}
