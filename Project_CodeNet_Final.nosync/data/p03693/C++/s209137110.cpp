#include <bits/stdc++.h>
using namespace std;

/* メモリ食い過ぎ注意 */
#define int long long

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (a < b)
        gcd(b, a);
    if (b == 0)
        return a;
    int r;
    while ((r = a % b))
    {
        a = b;
        b = r;
    }
    return b;
}

/* define const */
const ll INF = (1ll << 60);
const ll MOD = (ll)1e9 + 7;
/* end defineing */

signed main()
{
    int r, g, b;
    cin >> r >> g >> b;

    int tmp = 0;
    tmp += (r * 100);
    tmp += (g * 10);
    tmp += (b);

    if (tmp % 4 == 0)
        cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
    }
}
