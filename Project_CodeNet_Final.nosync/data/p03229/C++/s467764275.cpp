#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());

  vector<int> c(n, 2);
  for (int i = 1; i < n; i += 2) c[i] *= -1;
  c[0] /= abs(c[0]), c[n - 1] /= abs(c[n - 1]);
  sort(c.begin(), c.end());
  ll ans1 = 0;
  rep(i, n) ans1 += a[i] * c[i];

  vector<int> d(n, -2);
  for (int i = 1; i < n; i += 2) d[i] *= -1;
  d[0] /= abs(d[0]), d[n - 1] /= abs(d[n - 1]);
  sort(d.begin(), d.end());
  ll ans2 = 0;
  rep(i, n) ans2 += a[i] * d[i];

  cout << max(ans1, ans2) << endl;
  return 0;
}
