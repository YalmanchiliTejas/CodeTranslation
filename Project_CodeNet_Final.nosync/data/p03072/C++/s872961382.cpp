#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0; i < N; i++) cin >> H[i];
  
  int counter = 0;
  bool f;
  for(int i = 0; i < N; i++){
    f = false;
    for(int j = 0; j <= i; j++){
    if(H[i] < H[j]) f = true;
    }
  if(f == false) counter++;
  }
  cout << counter;
}


