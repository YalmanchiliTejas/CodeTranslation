#include <iostream>

int main(void){
  int n, h, h_max = 0, count = 0;
  std::cin >> n;
  for(int i=0; i<n; i++){
    std::cin >> h;
    if(h >= h_max){
        h_max = h;
        count++;
    }
  }
  std::cout << count << std::endl;
}