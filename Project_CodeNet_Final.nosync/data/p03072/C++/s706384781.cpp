#include <iostream>
using namespace std;

int N;
int H[21];  

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> H[i];
  int cnt = 1;
  
  if(N > 1){
     
  for (int i = 1; i < N; ++i){
    bool isGreatView = true;
    for (int j = 0; j < i; j++){
      if(H[i] < H[j]) isGreatView = false;
    }
    if(isGreatView) ++cnt; 
  }
    
  }

  cout << cnt << endl;

}