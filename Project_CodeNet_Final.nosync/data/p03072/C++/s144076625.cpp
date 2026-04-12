#include <iostream>

int main(void){
  int n;
  std::cin >> n;
  int *h = new int[n];
  int *max = new int[n];
  int count = 0;
  for(int i = 0; i < n; i++){
    std::cin >> h[i];
    if(i == 0){
      max[i] = h[i];
    }else{
      max[i] = (max[i - 1] > h[i]) ? max[i-1] : h[i];
    }
  }
  for(int i = 0; i < n; i++){
    if(i == 0){
      count++;
    }else if(h[i] >= max[i-1])
      count++;
  }
  std::cout << count << std::endl;
  return 0;
}
  