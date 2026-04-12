#include <iostream>

int main(){
  int a;
  std::cin >> a;
  if(a == 3 || a == 5 || a == 7){
    std::cout << "YES" << std::endl;
  }
  else{
    std::cout << "NO" << std::endl;
  }
}