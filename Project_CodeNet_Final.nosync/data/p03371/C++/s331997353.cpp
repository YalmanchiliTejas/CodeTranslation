#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<vector<int>>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e18
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = INF;
  for (int i = 0; i <= max(x, y); i++) {
    int X = max(0, x - i);
    int Y = max(0, y - i);
    ll val = X * a + Y * b + 2 * i * c;
    ans = min(ans, val);
  }
  cout << ans << endl;

  return 0;
}
