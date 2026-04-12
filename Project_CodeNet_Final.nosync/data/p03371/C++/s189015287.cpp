#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repd(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 100000000009;
    ll money;

    if (x > y)
    {
        rep(i, x + 1)
        {
            if (i < y)
            {
                money = 2 * c * i + a * (x - i) + b * (y - i);
            }
            else if (i >= y && i < x)
            {
                money = 2 * c * i + a * (x - i);
            }
            else
            {
                money = 2 * c * i;
            }
            ans = min(ans, money);
        }
    }

    else
    {
        rep(i, y + 1)
        {
            if (i < x)
            {
                money = 2 * c * i + a * (x - i) + b * (y - i);
            }
            else if (i >= x && i < y)
            {
                money = 2 * c * i + b * (y - i);
            }
            else
            {
                money = 2 * c * i;
            }
            ans = min(ans, money);
        }
    }

    cout << ans << endl;

    return 0;
}