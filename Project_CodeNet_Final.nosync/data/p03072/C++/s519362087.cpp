#include <iostream>
#include <vector>

int main(void){
  int n;
  std::cin >> n;
  std::vector<int> h(n);

  int height_max = -1;
  int count = 0;
  for(int i=0; i<n; i++){
    std::cin >> h[i];
    if (h[i] >= height_max){
      count++;
      height_max = h[i];
    }
  }
  std::cout << count << std::endl;
  return 0;
  
}
