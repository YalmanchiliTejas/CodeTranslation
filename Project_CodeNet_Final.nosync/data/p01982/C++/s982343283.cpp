#include <bits/stdc++.h>
using namespace std;
int main(){
  while (1){
    int n, l, r;
    cin >> n >> l >> r;
    if (n == 0 && l == 0 && r == 0){
      break;
    }
    vector<int> A(n);
    for (int i = 0; i < n; i++){
      cin >> A[i];
    }
    int ans = 0;
    for (int i = l; i <= r; i++){
      int m = n;
      for (int j = 0; j < n; j++){
        if (i % A[j] == 0){
          m = j;
          break;
        }
      }
      if (m % 2 == 0){
        ans++;
      }
    }
    cout << ans << endl;
  }
}
