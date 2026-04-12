#include <iostream>

int main()
{
  int a, b, c;
  std::cin >> a >> b >> c;
  if((10*b+c) % 4 == 0){
    std::cout << "YES";
  }else{
    std::cout << "NO";
  }
  return 0;
}