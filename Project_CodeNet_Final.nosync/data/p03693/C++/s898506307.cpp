#include<iostream>
#include<string>

int main(void){
  int r, g, b;
  std::cin >> r >> g >> b;
  if((100*r + 10*g + b) % 4 == 0){
    std::cout << "YES" << std::endl;
  }
  else {std::cout << "NO" << std::endl;}
  return 0;
}