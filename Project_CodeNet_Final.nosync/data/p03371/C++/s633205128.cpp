#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 1e18;
    for (ll i = 0; i <= max(x,y)*2; i++) {
        ans = min(ans, max(0LL, (x - i / 2)) * a + max(0LL, (y - i / 2)) * b + i * c);
    }
    cout << ans << endl;
    return 0;
}