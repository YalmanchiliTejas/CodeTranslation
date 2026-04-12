//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = min(x * a + y * b, max(x, y) * 2 * c);
    ll lownum;
    ll highnump;
    if(x > y) {
        lownum = y;
        highnump = a;
    }else {
        lownum = x;
        highnump = b;
    }
    ans = min(ans, lownum * 2 * c + abs(x-y) * highnump);
    cout << ans << endl;
    return 0;
}
