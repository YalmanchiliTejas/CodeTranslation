#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i, N) cin >> H[i];
  int count = 0;
  
  rep(i, N){
    bool can = true;
    rep(j, i){
      if(H[j] > H[i]){
        can = false;
        break;
      }
    }
    if(can) count++;
  }
  cout << count << endl;
  return 0;
}
