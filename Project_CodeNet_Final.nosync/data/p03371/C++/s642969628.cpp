#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 1001001001001001001;
    for (int i = 0; i <= 2 * max(x, y); i += 2)
    {
        ll cnt = a * max(x - i / 2, 0) + b * max(y - i / 2, 0) + c * i;
        if (cnt > 0)
        {
            ans = min(ans, cnt);
        }
    }

    cout << ans << '\n';
    return (0);
}
