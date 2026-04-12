#include<iostream>
using namespace std;

int main(){
  int r, g, b;
  std::cin >> r >> g >> b;
  std::cout << ((((100*r + 10*g + b)%4) == 0)?"YES":"NO") << std::endl;
  return 0;
}
