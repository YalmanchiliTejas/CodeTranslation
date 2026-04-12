#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int h[n];
  for (auto &v : h) cin >> v;
  int hmax = 0;
  int ans = 0;
  for (auto &v : h) if (hmax <= v) { ++ans; hmax = v; }
  cout << ans << endl;
}
