#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> as(n);
  for (auto &a : as) {
    cin >> a;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool f = true;
    for (int j = 0; j < i; j++) {
      f &= as[j] <= as[i];
    }
    if (f) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}