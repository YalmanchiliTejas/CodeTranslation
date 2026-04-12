#include <bits/stdc++.h>
using namespace std;

int main(){
  // input
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0; i < N; i++){
    cin >> H[i];
  }
  
  // compute
  int ans = 0;
  int MaxHeight = -1;
  
  for(int i = 0; i < N; i++){
    if(MaxHeight <= H[i]){
      ans++;
      MaxHeight = H[i];
    }
  }
  
  // output
  cout << ans << endl;
  return 0;
}