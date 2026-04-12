#include <iostream>

int main()
{
  int r, g, b;

  int a=0;

  std::cin >> r;
  std::cin >> g;
  std::cin >> b;

  a += r*100 + g*10 + b;

  if ( 0 == a%4){
    std::cout << "YES" << std::endl;
  }else {
    std::cout << "NO" << std::endl;
  }



}
