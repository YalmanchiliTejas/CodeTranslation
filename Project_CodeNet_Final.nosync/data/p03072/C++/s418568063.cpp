#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> H(N);
  for (int i=0; i<N; i++) std::cin >> H[i];
  
  int cnt = 0;
  for (int i=0; i<N; i++) {
    int flg = true;
    for (int j=0; j<i; j++) {
      if (H[j] > H[i]) flg = false;
    }
    if (flg) cnt++;
  }
  
  std::cout << cnt << std::endl;
  
  return 0;
}