#include <bits/stdc++.h>
using namespace std;

int main() {
  int room = 0;
  int view = 0;
  
  int N;
  cin >> N;
  
  vector<int> H(N);
  
  for (int k = 0; k < N; k++){
    cin >> H.at(k);
  }
  for (int i = 0; i < N; i++){
    for(int j = 0; j <= i; j++){
      if( H.at(i) >= H.at(j) ){
        view = 1;
      }
      else{
        view = 0;
        break;
      }
    }
    room = room + view;
  }
  cout << room << endl;
}