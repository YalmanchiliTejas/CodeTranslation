#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> H(N);
  for(auto &h:H)
    std::cin >> h;
  int cnt = 0;
  int max_h = H[0];
  for(auto &h:H){
    if(h >= max_h){
      max_h = h;
      cnt++;
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}
