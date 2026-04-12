//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll minv;
    ll minn;
    ll maxv;
    ll maxn;
    if(x <= y) {
        minv = a;
        minn = x;
        maxv = b;
        maxn = y;
    }else {
        minv = b;
        minn = y;
        maxv = a;
        maxn = x;

    }

    ll ans = min(x*a+y*b, 2 * maxn * c);
    ans = min(ans, 2 * minn * c + (maxn- minn) * maxv);
    cout << ans << endl;

    return 0;
}
