#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = x * a + y * b;
  ans = min(ans, max(x, y) * 2 * c);
  if (x > y) {
    ans = min(ans, a * (x - y) + y * 2 * c);
  } else {
    ans = min(ans, x * 2 * c + b * (y - x));
  }
  cout << ans << endl;
}
