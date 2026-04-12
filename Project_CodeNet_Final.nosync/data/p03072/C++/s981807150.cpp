#include <iostream>
#include <vector>

int main(){
  
  int N;
  std::cin >> N;
  std::vector<int> Hs(N);
  for(int i = 0; i < N; ++i) std::cin >> Hs[i];
  
  int count = 0;
  int maxH = 0;
  for(const auto &Hi : Hs){
  	 if(Hi >= maxH){
       ++count;
       maxH = Hi;
     } 
  }
  std::cout << count; 
  
  return 0;
}