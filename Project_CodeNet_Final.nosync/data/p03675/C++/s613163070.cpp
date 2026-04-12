#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  reverse(a.begin(), a.end());

  vector<int> ans(n);
  int l = 0, r = n - 1, sgn = 1;

  for (int i = 0; i < n; i++) {
    if (sgn > 0) {
      ans[l++] = a[i];
    } else {
      ans[r--] = a[i];
    }
    sgn ^= 1;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}