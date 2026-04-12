#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
typedef long long llong;
const int inf = 1 << 20;
const int mod = 1e9 + 7;

int main() {
   int a, b, c, x, y;
   cin >> a >> b >> c >> x >> y;
   int ans = 1e9;
   rep(k, 1e5 + 1) {
      int cost = a * max(x - k, 0) + b * max(y - k, 0) + c * 2 * k;
      ans = min(ans, cost);
   }
   cout << ans << endl;
   return 0;
}