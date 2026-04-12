#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int res[n];
  if (n % 2) {
    for (int i = 0; i < n; i++) {
      if (i % 2) res[n / 2 + i / 2 + 1] = a[i];
      else res[n / 2 - i / 2] = a[i];
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (i % 2) res[n / 2 - i / 2 - 1] = a[i];
      else res[n / 2 + i / 2] = a[i];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << "" << "\n";
  return 0;
}