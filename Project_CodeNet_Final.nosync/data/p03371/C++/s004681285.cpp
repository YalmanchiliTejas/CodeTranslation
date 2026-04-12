#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int mx = max(x, y);
    ll ans = 1e18;
    for (int i = 0; i <= 2 * mx; i += 2) {
        ll tmp = 0;
        tmp += c * i;
        int x2 = max(x - i / 2, 0);
        int y2 = max(y - i / 2, 0);
        tmp += a * x2 + b * y2;
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}
