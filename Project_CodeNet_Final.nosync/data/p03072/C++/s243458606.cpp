#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> hi(n);
  for (int i = 0; i < n; i++) cin >> hi.at(i);
  
  int ans = 0;
  int h = hi.at(0);
  for (int i = 0; i < n; i++) {
    if (h <= hi.at(i)) ans++;
    h = max(h, hi.at(i));
  }
  cout << ans << endl;
}