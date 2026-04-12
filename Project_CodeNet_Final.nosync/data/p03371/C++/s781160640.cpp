#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, x, y, ans;
    cin >> a >> b >> c >> x >> y;

    if (x > y)
        ans = 2 * y * c + (x - y) * min(2 * c, a);
    else
        ans = 2 * x * c + (y - x) * min(2 * c, b);
    ans = min(ans, a * x + b * y);

    cout << ans << '\n';

    return 0;
}
