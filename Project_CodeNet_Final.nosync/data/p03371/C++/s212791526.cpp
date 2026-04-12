#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans;
    if ((a + b) <= 2 * c) ans = a * x + b * y;
    else {
        ans = 2 * c * min(x, y);
        int rest = abs(x - y);
        if (x < y) {
            ans += min(b * rest, 2 * c * rest);
        } else {
            ans += min(a * rest, 2 * c * rest);
        }
    }
    cout << ans << endl;
    return 0;
}