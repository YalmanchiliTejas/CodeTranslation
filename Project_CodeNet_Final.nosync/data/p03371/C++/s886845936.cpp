#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int p1 = a * x + b * y;
  int p2 = max(x, y) * c * 2;
  int p3 = min(x, y) * c * 2;
  if (x >= y)
    p3 += (x - y) * a;
  else
    p3 += (y - x) * b;
  cout << min({p1, p2, p3}) << endl;
}
