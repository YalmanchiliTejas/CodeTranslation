#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int H[N];
  for(int i = 0;i<N;i++){
    cin >> H[i];
  }
  int sum = 0;
  int left_max = 0;

  for(int i=0; i<N; i++){
    if(left_max <= H[i]){
      sum += 1;
      left_max = H[i];
    }
  }
  std::cout << sum << std::endl;
  return 0;
}