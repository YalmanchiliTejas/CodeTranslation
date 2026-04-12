#include <iostream>
using namespace std;

int main(){
  int N;
  int H[110];
  cin >> N;
  for(int i = 0; i < N; ++i) cin >> H[i];
  int sum = 0;
  int max = H[0];
  for(int i = 0; i < N; ++i){
    if(H[i] >= max){
      ++sum;
      max = H[i];
    }
  }
  cout << sum << endl;
}