#include<iostream>

int main(){
  int X, Y, Z;
  std::cin >> X >> Y >> Z;
  std::cout << 1 + (X - (2 * Z + Y)) / (Z + Y) << std::endl;
}