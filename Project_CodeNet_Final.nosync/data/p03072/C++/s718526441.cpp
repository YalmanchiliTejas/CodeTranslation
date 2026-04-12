#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int H[N];
  int max = 0;
  int count = 0;
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
    if(H[i] >= max){
      count++;
      max = H[i];
    }
  }
  
  cout << count << endl;
}