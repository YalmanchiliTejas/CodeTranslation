#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = min({a * x + b * y, max(x, y) * c * 2, min(x, y) * c * 2 + (x - min(x, y)) * a + (y - min(x, y)) * b});
    cout << ans << "\n";
}