#include <iostream>

int main(int argc, char const *argv[]) {
  int r=0,g=0,b=0,t=0;
  std::cin>>r>>g>>b;
  t=r*100+g*10+b;
  if(t%4==0){
    std::cout << "YES" << '\n';
  }else{
    std::cout << "NO" << '\n';
  }
  return 0;
}
