#include <bits/stdc++.h>
using namespace std;

int main(){
  // input
  int N; cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  
  // compute
  int ans = 0;
  for (int i = 0; i < N; i++) {
    bool flag = true;
    for (int j = 0; j < i; j++) {
      if (H[i]<H[j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
    ++ans;
    }
  }
  
  
  // output
  cout << ans << endl;
}