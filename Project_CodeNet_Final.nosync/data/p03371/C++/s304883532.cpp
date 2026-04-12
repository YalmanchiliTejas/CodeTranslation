#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define INF 1e9;
using namespace std;
typedef long long ll;
int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  c *= 2;
  ll c1, c2, c3;
  c1 = a * x + b * y;
  c2 = c * max(x, y);
  if (x < y) {
    c3 = x * c + (y - x) * b;
  } else if (x > y) {
    c3 = y * c + (x - y) * a;
  } else {
    c3 = c2;
  }
  cout << min(c1, min(c2, c3)) << endl;
  return 0;
}