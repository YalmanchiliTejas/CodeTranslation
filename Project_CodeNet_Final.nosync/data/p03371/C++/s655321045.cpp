#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const string ln = "\n";
constexpr int INF = 1001001001;
constexpr int MOD = 1000000007;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  ll ans = -1;
  for (int i = 0; i <= max(x, y); i++) {
    ll cc = i * 2 * c;
    ll ac = max(x - i, 0) * a;
    ll bc = max(y - i, 0) * b;

    ll total = ac + bc + cc;

    if (ans == -1 || ans > total) {
      ans = total;
    }
  }

  cout << ans << ln;

  return 0;
}