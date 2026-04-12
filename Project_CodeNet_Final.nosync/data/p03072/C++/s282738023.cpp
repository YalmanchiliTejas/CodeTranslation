#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int maxH = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= maxH) {
      res += 1;
      maxH = a[i];
    }
  }
  cout << res << '\n';
  return 0;
}