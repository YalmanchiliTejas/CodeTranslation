#include <bits/stdc++.h>

#define debug(s) cout << s << endl
#define debug1(s, t) cout << s << " " << t << endl
#define debug2(s, t, u) cout << s << " " << t << " " << u << endl
#define printvec(v)       \
    for (auto &&i : v)    \
        cout << i << " "; \
    cout << endl

using namespace std;
using i64 = long long;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans;
    if (2 * c >= a + b)
    {
        ans = a * x + b * y;
    }
    else
    {
        ans = 2 * c * min(x, y);
        if (x > y)
        {
            ans += min(2 * c, a) * (x - y);
        }
        else
        {
            ans += min(2 * c, b) * (y - x);
        }
    }

    cout << ans << endl;

    return 0;
}