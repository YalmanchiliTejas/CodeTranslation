#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    int x_rest = x;
    int y_rest = y;
    if ( a + b >= c * 2 ) {
        ans += min(x, y) * 2 * c;
        x_rest -=  min(x,y);
        y_rest -=  min(x,y);
    }
    if ( x_rest >= 0 ) {
        if ( a >= c * 2 ) {
            ans += c * 2 * x_rest;
            x_rest = 0;
            y_rest = max(0, y_rest - x_rest);
        }
    }
    if ( y_rest >= 0 ) {
        if ( b >= c * 2 ) {
            ans += c * 2 * y_rest;
            y_rest = 0;
            x_rest = max(0, x_rest - y_rest);
        }
    }
    ans += x_rest * a + y_rest * b;
    cout << ans << endl;
    return 0;
}
