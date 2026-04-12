#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> h(n);
  for(int i=0; i<n; i++) cin >> h[i];
 
  int x = h[0];
  int ans=1;
  for(int i=1;i<n;++i) {
    if (max(x,h[i]) == h[i]) {
      ans++;
      x = h[i];
    }
  }
  
  cout << ans << endl;

  return 0;
}