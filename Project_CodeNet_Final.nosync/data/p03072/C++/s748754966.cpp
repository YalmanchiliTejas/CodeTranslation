#include <bits/stdc++.h>
using namespace std;

int h[1005];

int main() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> h[i];
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    bool ok = true;
    for (int j = 1; j < i; j++)
      ok = ok && h[j] <= h[i];
    ans += ok ? 1 : 0;
  }
  cout << ans << endl;
}