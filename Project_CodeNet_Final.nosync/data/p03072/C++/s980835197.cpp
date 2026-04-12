#include <iostream>

int main(){
  int N = 0;
  int H[100];
  int takai = 0;
  int count= 0;
  std::cin >> N;

  for(int i = 0; i < N; i++){
    std::cin >> H[i];
    if(takai <= H[i]){
      takai = H[i];
      count++;
    }
  }
  std::cout << count << std::endl;


}
