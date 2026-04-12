#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i, n) cin >> h[i];
  vector<int> a(n + 1);
  rep(i, n) a[i + 1] = max(a[i], h[i]);

  int ans = 0;
  rep(i, n) if (h[i] >= a[i])++ ans;
  cout << ans << endl;
  return 0;
}
