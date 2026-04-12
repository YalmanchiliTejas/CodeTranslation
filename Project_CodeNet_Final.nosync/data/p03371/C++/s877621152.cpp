#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if ((a + b) >= (c * 2)) {
        int minxy = min(x, y);
        ans += minxy * c * 2;
        x -= minxy;
        y -= minxy;
        // cout << "bought c: " << minxy << endl;
    }
    if (a >= (c*2)) {
        ans += c * 2 * x;
        y -= x;
    } else {
        ans += a * x;
        // cout << "bought a: " << x << endl;
    }
    y = max(0, y);
    if (b >= (c*2)) {
        ans += c * 2 * y;
    } else {
        ans += b * y;
        // cout << "bought b: " << y << endl;
    }

    cout << ans << endl;
    return 0;
}