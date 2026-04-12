#include <iostream>
#include <vector>

int main(){
  int N;
  std::cin >> N;
  std::vector<int> H(N);
  for(int i=0;i<N;i++) std::cin >> H.at(i);
  int count = 0;
  int max=0;
  for(int i=0;i<N;i++){
    if(H.at(i)>=max){
      count++;
      max=H.at(i);
    }
  }

  std::cout << count << std::endl;
  return 0;
}
