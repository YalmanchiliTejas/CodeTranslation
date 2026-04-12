#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

ll MOD = 1000000007;

int main()
{
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = LLONG_MAX, tmp = 0;
    ll tmp_x, tmp_y;

    ll m = max(x, y);
    m *= 2;

    for (ll i = 0; i <= m; i += 2)
    {
        tmp_x = x - i / 2;
        tmp_y = y - i / 2;
        if (tmp_x < 0)
            tmp_x = 0;

        if (tmp_y < 0)
            tmp_y = 0;

        tmp = a * tmp_x + b * tmp_y + c * i;

        if (ans > tmp)
        {
            ans = tmp;
        }
    }

    cout << ans << endl;
}
