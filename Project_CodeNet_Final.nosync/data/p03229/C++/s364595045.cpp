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

  vector<int> c(n, 1);
  for (int i = 1; i < n; i += 2) c[i] *= -1;
  for (int i = 1; i < n - 1; i++) c[i] *= 2;
  sort(c.begin(), c.end());
  ll ans1 = 0;
  rep(i, n) ans1 += a[i] * c[i];

  vector<int> d(n, -1);
  for (int i = 1; i < n; i += 2) d[i] *= -1;
  for (int i = 1; i < n - 1; i++) d[i] *= 2;
  sort(d.begin(), d.end());
  ll ans2 = 0;
  rep(i, n) ans2 += a[i] * d[i];

  cout << max(ans1, ans2) << endl;
  return 0;
}
