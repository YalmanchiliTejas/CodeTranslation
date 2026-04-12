#include <iostream>

int main(){
  char Station[3];

  std::cin >> Station;

  for(int i=1;i<3;i++){
    if(Station[i] != Station[i-1]){
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }

  std::cout << "No" << std::endl;
  return 0;
}
