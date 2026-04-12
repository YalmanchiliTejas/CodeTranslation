#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans = INT_MAX;

  for (const int i : boost::irange(0, max(X, Y) + 1)) {
    int price = 2 * C * i + A * max(0, X - i) + B * max(0, Y - i);
    ans = min(ans, price);
  }

  cout << ans << endl;
  return 0;
}
