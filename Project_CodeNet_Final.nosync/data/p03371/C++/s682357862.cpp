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

    int ans = a * x + b * y;

    int highp, lownum;
    if(x <= y) {
        lownum = x;
        highp = b;
    }else {
        lownum = y;
        highp= a;
    }
    ans = min(ans, lownum * 2 * c + abs(x - y) * highp);
    ans = min(ans, 2 * c * max(x, y));
    cout << ans << endl;
    return 0;
}
