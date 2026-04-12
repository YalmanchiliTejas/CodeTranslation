#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int A, B, C, x, y;
  cin >> A >> B >> C >> x >> y;

  int last = 2 * max(x, y);
  int ans = 1001001001;
  for (int c = 0; c <= last; c += 2) {
    int a = max(0, x - c / 2);
    int b = max(0, y - c / 2);
    ans = min(ans, a * A + b * B + c * C);
  }
  cout << ans << endl;
  return 0;
}
