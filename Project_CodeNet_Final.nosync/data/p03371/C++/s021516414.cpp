#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans1 = x * a + y * b;
  ll ans2;
  if (x >= y) {
    ans2 = y * (2 * c) + (x - y) * a;
  } else {
    ans2 = x * (2 * c) + (y - x) * b;
  }
  ll ans3 = max(x, y) * (2 * c);
  cout << min({ans1, ans2, ans3}) << endl;
  return 0;
}