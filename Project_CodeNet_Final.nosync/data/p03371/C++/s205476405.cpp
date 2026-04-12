#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using  namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  ans += min(a+b, 2*c) * min(x, y);
  ans += (x < y ? min(b, 2*c)*(y-x) : min(a, 2*c)*(x-y));
  cout << ans << endl;
  return 0;
}