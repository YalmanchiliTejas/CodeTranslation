#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 1e18;
    for (int i = 0; i <= max(x,y); i++) {
        ll aa = max(0LL, x - i);
        ll bb = max(0LL, y - i);
        ans = min(ans, aa * a + bb * b + c * i * 2);
    }
    cout << ans << endl;
    return 0;
}