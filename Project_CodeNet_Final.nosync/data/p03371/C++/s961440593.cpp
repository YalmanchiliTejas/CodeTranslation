#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int x_rest = x;
    int y_rest = y;
    int min_s = min(x, y);
    int ans = 0;
    if ( a + b >= c * 2 ) {
        ans += c * 2 * min_s;
        x_rest -= min_s;
        y_rest -= min_s;
    }
    bool flg = false;
    if ( x_rest > y_rest ) {
        flg = true;
    }
    if ( flg ) {
        if ( x_rest > 0 ) {
            if ( a * x_rest > c * x_rest * 2 ) {
                y_rest -= x_rest;
                ans += c * x_rest * 2;
            }
            else {
                ans += a * x_rest;
            }
        }
        if ( y_rest > 0 ) {
            ans += min(b * y_rest, c * y_rest * 2 );
        }
    }
    else {
        if ( y_rest > 0 ) {
            if ( b * y_rest > c * y_rest * 2 ) {
                x_rest -= y_rest;
                ans += c * y_rest * 2;
            }
            else {
                ans += b * y_rest;
            }
        }
        if ( x_rest > 0 ) {
            ans += min(a * x_rest, c * x_rest * 2 );
        }
    }
    cout << ans << endl;
    return 0;
}
