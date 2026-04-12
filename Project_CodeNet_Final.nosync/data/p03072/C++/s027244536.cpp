#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; ++i) cin >> h.at(i);
  
  int mx = 0;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    if(mx > h.at(i)) continue;
    ans++;
    mx = max(mx, h.at(i));
  }
  
  cout << ans << endl;
}