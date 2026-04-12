#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define FOR(i, m, n) for(int i = (m); i < (n); i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;
typedef long long ll;

signed main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int n = a * x + b * y;
  int m = 2 * c * max(x, y);
  int p = x > y ? a : b;
  int l = 2 * c * min(x, y) + p * abs(x - y);

  cout << min(n, min(m, l)) << endl;
  return 0;
}
