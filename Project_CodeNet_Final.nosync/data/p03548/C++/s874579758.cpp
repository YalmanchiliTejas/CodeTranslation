#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL x, y, z, res;

    cin >> x >> y >> z;

    for (res = 50000; res > 0; res--)
    {
        if (y * res + z * (res + 1) <= x)
        {
            break;
        }
    }

    cout << res << endl;

    return 0;
}