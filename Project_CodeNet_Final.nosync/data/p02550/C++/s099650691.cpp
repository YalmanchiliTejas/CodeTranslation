#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n, x, m, len = 0, total = 0;
  cin >> n >> x >> m;
  vector<int> id(m, -1);
  vector<int> a;
  while (id[x] == -1) {
    a.push_back(x);
    id[x] = len;
    len++;
    total += x;
    x = (x * x) % m;
  }

  int c = len - id[x];
  ll s = 0;
  for (int i = id[x]; i < len; i++) s += a[i];

  ll ans = 0;
  if (n <= len) {
    rep(i, n) ans += a[i];
  } else {
    ans += total;
    n -= len;
    ans += s * (n / c);
    n %= c;
    rep(i, n) ans += a[id[x] + i];
  }
  cout << ans << endl;
  return 0;
}
