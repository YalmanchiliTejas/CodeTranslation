#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int h[n];
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int ans = 1;
  for(int i = 1; i < n; i++) {
    bool f = 1;
    for(int j = 0; j < i; j++) {
      if(h[i] < h[j]) f = 0;
    }
    if(f) ans++;
  }
  cout << ans << endl;
  return 0;
}
