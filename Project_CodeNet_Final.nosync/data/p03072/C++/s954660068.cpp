#include <iostream>
#include <vector>

int main(){
  int n;
  std::cin >> n;
  std::vector<int> h(n);
  for(int i = 0; i < n; ++i)
    std::cin >> h[i];

  int ans = 0;
  int maxH = 0;

  for(int i = 0; i < n; ++i){
    if(h[i] >= maxH){
      ++ans;
      maxH = h[i];
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
