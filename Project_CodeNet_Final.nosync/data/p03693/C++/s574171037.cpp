#include<iostream>

int main(){
  int a, b, c;
  std::cin >> a >> b >> c;
  int x = (a*100) + (b*10) + c;
  if(x%4 == 0)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
  return 0;
}