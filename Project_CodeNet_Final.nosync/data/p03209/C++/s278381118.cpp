#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

ll n, x;
vector<ll> a, p;

ll calcPatty(ll n, ll x) {
  if (n == 0) return 1;
  if (x == 1)
    return 0;
  else if (x <= a[n - 1] + 1)
    return calcPatty(n - 1, x - 1);
  else if (x == a[n - 1] + 2)
    return p[n - 1] + 1;
  else if (x <= 2 * a[n - 1] + 2)
    return p[n - 1] + 1 + calcPatty(n - 1, x - 2 - a[n - 1]);
  else
    return 2 * p[n - 1] + 1;
}

int main() {
  cin >> n >> x;
  a.resize(n);
  p.resize(n);
  a[0] = 1;
  p[0] = 1;
  repi(i, 1, n) {
    p[i] = 1 + 2 * p[i - 1];
    a[i] = 3 + 2 * a[i - 1];
  }
  cout << calcPatty(n, x) << endl;
  return 0;
}
