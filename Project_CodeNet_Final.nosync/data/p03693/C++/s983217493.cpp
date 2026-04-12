//ABC 064 A - RGB Cards
#include <iostream>

int main(void){
  int n,r,g,b;
  std::cin >> r >> g >> b;
  n = 100*r + 10*g + b;
  std::cout << ((n%4 == 0) ?"YES" :"NO" ) << std::endl;

  return 0;
}