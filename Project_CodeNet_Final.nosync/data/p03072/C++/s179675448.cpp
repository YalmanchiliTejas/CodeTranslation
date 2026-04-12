#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, i = 0, r = 1, m;
  cin >> n;
  vector<int> h(n);
  for(; i < n; i++) cin >> h[i];
  m = h[0];
  for(i = 1; i < n; i++) {
    if(m <= h[i]) {
      m = h[i];
      r++;
    }
  }
  cout << r << endl;
  return 0;
}