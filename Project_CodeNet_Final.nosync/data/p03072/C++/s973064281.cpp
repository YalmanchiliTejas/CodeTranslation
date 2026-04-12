#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, h_before, h;
  cin >> N;
  int count = 0;
  for(int i = 0; i < N; i++){
    cin >> h;
    if(h >= h_before){
      h_before = h;
      count++;
    }
  }
  cout << count;
  return 0;
  
}