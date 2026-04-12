#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const int mod = 1e9 + 7;

int main()
{
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long ans = 0;

    bool flag;
    if (x >= y)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }

    if (a + b >= 2 * c)
    {
        ans += 2 * c * min(x, y);
    }
    else
    {
        ans += (a + b) * min(x, y);
    }

    if ((a >= 2 * c) && flag)
    {
        ans += 2 * c * (x - y);
    }
    else if (flag)
    {
        ans += a * (x - y);
    }

    if ((b >= 2 * c) && !flag)
    {
        ans += 2 * c * (y - x);
    }
    else if (!flag)
    {
        ans += b * (y - x);
    }

    cout << ans << endl;
    return 0;
}