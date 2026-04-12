#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;
int main()
{
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = x * a + y * b;
    ans = min(ans, max(x, y) * c * 2);
    ans = min(ans, x * c * 2 + max(0LL, y-x) * b);
    ans = min(ans, y * c * 2 + max(0LL, x-y) * a);
    cout << ans << endl;
}
