#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a;
  cin >> n >> a;
  
  int ans = 1, h = a, b;
  for (int i = 0; i < n-1; i++) {
    cin >> b;
    if (h <= b) {
      ans ++;
      h = max(h, b);
    }
  }
  cout << ans << endl;
}