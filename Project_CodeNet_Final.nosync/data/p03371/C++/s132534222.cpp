#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  long long cost = 1000000000;
  for (int ab = 0; ab <= 200000; ab += 2) {
    cost = min(cost, (ll)(c * ab) + (ll)(a * max(0ll, x - ab/2)) + (ll)(b * max(0ll, y - ab/2)));
  }
  cout << cost << endl;
}
