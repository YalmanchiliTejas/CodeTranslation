#include <iostream>

int main()
{
  int r,g,b;      //カード
  int integer;    //3桁の整数

  std::cin >> r >> g >> b;

  integer = r*100 + g*10 + b*1;

  if(integer%4 == 0){
    std::cout << "YES" << '\n';
  }else{
    std::cout << "NO" << '\n';
  }

  return (0);
}
