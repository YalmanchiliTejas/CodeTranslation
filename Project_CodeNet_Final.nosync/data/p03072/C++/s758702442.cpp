#include <bits/stdc++.h>
using namespace std;
int main(void){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0; i < N; i++) cin >> H[i];
  int H_MAX = H[0];
  int Count = 0;
  for(int i = 0; i < N; i++){
      if(H_MAX <= H[i]){
          Count++;
          H_MAX = H[i];
      }
  }
  cout << Count << endl;
 }
