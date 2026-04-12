#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n;
  cin >> n;
  V<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());

  if (a.size() == 1) {
    cout << a[0] << endl;
    return 0;
  }

  int half = a.size() / 2;

  if (a.size() % 2 == 0) {
    ll sm = 0, la = 0;
    for (int i = 0; i < half; i++) sm += a[i] * 2;
    sm -= a[half - 1];
    for (int i = a.size() / 2; i < n; i++) la += a[i] * 2;
    la -= a[half];

    ll ans = la - sm;
    cout << ans << endl;
    return 0;
  }

  ll ans = 0;

  ll sm = 0, la = 0;
  for (int i = 0; i < half; i++) sm += a[i] * 2;
  for (int i = half; i < n; i++) la += a[i] * 2;
  la -= a[half] + a[half + 1];
  ans = max(ans, la - sm);

  sm = 0;
  la = 0;
  for (int i = 0; i < half + 1; i++) sm += a[i] * 2;
  for (int i = half + 1; i < n; i++) la += a[i] * 2;
  sm -= a[half] + a[half - 1];
  ans = max(ans, la - sm);

  cout << ans << endl;
}
