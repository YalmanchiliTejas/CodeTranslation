#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >>n;
  int mh = 0;
  int c = 0;
  for(int i=0;i<n;++i){
    int a;
    std::cin >>a;
    if(mh <= a){
      c++;
      mh = a;
    }
  }
  
    std::cout << c << std::endl;
}