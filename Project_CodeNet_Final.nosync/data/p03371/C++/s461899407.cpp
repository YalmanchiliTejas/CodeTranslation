#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    c *= 2;

    ll ans = 0;
    ll cnt = min(x, y);
    ans += cnt * min(a + b, c);
    x-= cnt; y -= cnt;

    if (x > 0) {
        ans += x * min(a, c);
    }
    if (y > 0) {
        ans += y * min(b, c);
    }
    cout << ans << endl;
    return 0;
}