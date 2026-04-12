#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    long long ans = 0;
    if (a + b <= c * 2) {
        ans = a * x + b * y;
    } else {
        if (x > y) {
            ans = min(y * c * 2 + (x - y) * a, x * c * 2);
        } else {
            ans = min(x * c * 2 + (y - x) * b, y * c * 2);
        }
    }
    cout << ans << '\n';
}