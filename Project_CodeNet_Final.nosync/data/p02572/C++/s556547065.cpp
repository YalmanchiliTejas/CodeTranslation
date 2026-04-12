#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sm = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    (sm += a[i]) %= md;
    (res += 1ll * a[i] * a[i] % md) %= md;
  }
  res = (1ll * sm * sm % md - res) % md;
  (res += md) %= md;
  res = (1ll * res * (md + 1) / 2) % md;
  cout << res << endl;
  return 0;
}
