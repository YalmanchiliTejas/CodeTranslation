#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {

    ll a, b, ab, x, y;

    cin >> a >> b >> ab >> x >> y;

    ll minXY = min(x, y);

    ll ans = minXY * min(a + b, 2 * ab);

    if(x > y) {
        ll restX = x - y;
        ans += restX * min(a, 2 * ab);
    }
    else {
        ll restY = y - x;
        ans += restY * min(b, 2 * ab);
    }

    cout << ans << endl;

    return 0;
}