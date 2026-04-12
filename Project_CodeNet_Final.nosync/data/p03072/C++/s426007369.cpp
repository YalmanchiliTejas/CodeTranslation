#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i,n) cin >> h[i];
  int ans = 1;
  int m = h[0];
  for(int i = 1; i < n; i++) {
    if(h[i] >= m) ans++;
    m = max(h[i],m);
  } 
  cout << ans << endl;
}
