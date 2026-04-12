#include <iostream>

int main(){
  int n;
  int h[100];
  std::cin >> n;
  for(int i = 0; i < n; i++) std::cin >> h[i];

  int ret = 1;
  for(int i = 1; i < n; i++){
    bool can_see = true;
    for(int j = 0; j < i; j++){
      if(h[j] > h[i]){
        can_see = false;
        break;
      }
    }
    if(can_see)
      ret++;
  }

  std::cout << ret << std::endl;
  return 0;
}
