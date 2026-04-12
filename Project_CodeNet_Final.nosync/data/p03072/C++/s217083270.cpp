#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i, n) cin >> h[i];

  vector<int> s(n + 1);
  rep(i, n) s[i + 1] = max(s[i], h[i]);

  int ans = 0;
  rep(i, n) ans += (h[i] >= s[i]);
  cout << ans << endl;

  return 0;
}
