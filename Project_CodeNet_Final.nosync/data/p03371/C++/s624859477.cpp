#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int n = max(x, y);
    int ans = 1e9;
    rep(i, n+1) {
        int cost = 2 * c * i;
        if (x >= i) cost += a * (x - i);
        if (y >= i) cost += b * (y - i);
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}