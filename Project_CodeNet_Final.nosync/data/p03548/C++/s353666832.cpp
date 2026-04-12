#include <bits/stdc++.h>
using namespace std;

/* メモリ食い過ぎ注意 */
#define int long long

typedef long long ll;

ll gcd(ll a, int b)
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
    int x, y, z;
    cin >> x >> y >> z;

    x -= z;
    cout << (x / (y + z)) << endl;
}
