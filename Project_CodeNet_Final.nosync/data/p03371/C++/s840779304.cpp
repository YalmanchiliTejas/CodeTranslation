#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const long long INF = 1LL << 60;
using namespace std;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int iter = max(x, y);
    ll ans = INF;

    rep(i, 100001)
    {
        ll tmp = 0;
        tmp += c * 2 * i;

        if (i < x)
        {
            tmp += a * (x - i);
        }

        if (i < y)
        {
            tmp += b * (y - i);
        }

        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}