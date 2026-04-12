#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> pr;
typedef vector<ll> vll;
typedef vector<vector<int>> vv;
typedef vector<vector<ll>> vvll;
const ll inf = 1e16;
const ll md = 1000000007;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = a * x + b * y;
  if (x > y)
    ans = min(ans, c * y * 2 + a * (x - y));
  else
    ans = min(ans, c * x * 2 + b * (y - x));
  ans = min(ans, max(x, y) * c * 2);
  cout << ans << endl;
  return 0;
}
