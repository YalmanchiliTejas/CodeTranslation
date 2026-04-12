#include <bits/stdc++.h>

using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, a, b) for (int64_t i = (a); i < (b); ++i)
const int MOD = 1e9 + 7;
typedef long long ll;
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  SORT(a);
  ll total1 = 0;
  ll total2 = 0;
  if (n % 2) {
    rep(i, 0, n / 2) total1 -= 2 * a[i];
    rep(i, n / 2, n / 2 + 2) total1 += a[i];
    rep(i, n / 2 + 2, n) total1 += 2 * a[i];

    rep(i, 0, n / 2 - 1) total2 -= 2 * a[i];
    rep(i, n / 2 - 1, n / 2 + 1) total2 -= a[i];
    rep(i, n / 2 + 1, n) total2 += 2 * a[i];
  } else {
    total1 = a[n / 2] - a[n / 2 - 1];
    rep(i, 0, n / 2 - 1) total1 -= 2 * a[i];
    rep(i, n / 2 + 1, n) total1 += 2 * a[i];
  }

  cout << max(total1, total2) << endl;
}
