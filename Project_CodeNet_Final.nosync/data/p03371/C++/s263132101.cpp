#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans;
    if (a + b < c * 2) {
        ans = a * x + b * y;
    } else {
        int tmp1, tmp2;
        if (x < y) {
            tmp1 = x * 2 * c + (y - x) * b;
            tmp2 = y * 2 * c;
        } else {
            tmp1 = y * 2 * c + (x - y) * a;
            tmp2 = x * 2 * c;
        }
        ans = min(tmp1, tmp2);
    }

    cout << ans << endl;

    return 0;
}
