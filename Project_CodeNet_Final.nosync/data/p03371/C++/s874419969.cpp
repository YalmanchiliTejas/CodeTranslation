#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define fill(v, h) memset((v), h, sizeof(v))
using namespace std;
const int MOD = 1000000007;

template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}

int main(void)
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans2 = a * x + b * y;

    int ans = 0;
    int mi = min(x, y);
    ans += c * mi * 2;
    ans += a * (x - mi);
    ans += b * (y - mi);

    int ans3 = 0;
    if (x >= y)
    {
        ans3 = c * x * 2;
    }
    else
    {
        ans3 = c * y * 2;
    }

    cerr << ans << " " << ans2 << " " << ans3 << " " << endl;
    cout << min(min(ans, ans2), ans3) << endl;
    return 0;
}