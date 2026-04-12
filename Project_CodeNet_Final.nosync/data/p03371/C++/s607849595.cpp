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

  ll p1 = a * x + b * y;
  ll p2 = c * x * 2 + max(y - x, 0) * b;
  ll p3 = c * y * 2 + max(x - y, 0) * a;

  cout << min(p1, min(p2, p3)) << ln;

  return 0;
}