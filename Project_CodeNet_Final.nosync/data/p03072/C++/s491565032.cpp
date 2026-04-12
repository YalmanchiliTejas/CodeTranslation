#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int h[25];
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  int m = 0, ans = 0;
  for (int i = 0; i < n; i++){
    if (h[i] >= m) ans++;
    m = max(m, h[i]);
  }
  cout << ans << endl;
  return 0;
}