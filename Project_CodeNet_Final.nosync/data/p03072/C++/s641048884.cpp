
#include <iostream>
#include <vector>

std::vector<int> H;

bool count(int i){
  for(int j=0; j<i; j++) if ( !(H[i] >= H[j]) ) return false;
  return true;
}


int main (void){
  int N; std::cin >> N ;

  H.resize(N);
  for(int i=0; i<N; i++) std::cin >> H[i];

  int ans = 0;
  for(int i=0; i<N; i++) if (count(i)) ans++;

  std::cout << ans << std::endl;
  return 0;
}