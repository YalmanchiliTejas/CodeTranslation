#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    c *= 2;

    ll r = 1e9;
    for(ll t=0; t <= max(x, y); t++)
        r = min(r, t*c + max(0ll, x-t)*a + max(0ll, y-t)*b);
    cout << r << endl;
}
