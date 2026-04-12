#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), ord(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ord[i] = i;
  }
  sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
  int x = a[ord[n / 2 - 1]];
  int y = a[ord[n / 2]];
  for (int i = 0; i < n; i++) {
    if (a[i] <= x) cout << y << '\n';
    else cout << x << '\n';
  }
  return 0;
}