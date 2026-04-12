#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main()
{
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = ll(1e18)+1;
    for (ll k=0; k<=int(2e5); k+=2) {
        int a_loss = max(x- k/2, 0LL);
        int b_loss = max(y- k/2, 0LL);
        ll tmp = a_loss * a + b_loss * b + k * c;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}