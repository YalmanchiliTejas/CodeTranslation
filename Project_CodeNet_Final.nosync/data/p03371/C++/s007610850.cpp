#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    ll maxval = max(x, y);
    ll minval = min(x, y);
    ans += min(minval*c*2, minval*(a+b));
    if (x > y) ans += a * (x - minval);
    else ans += b * (y - minval);

    cout << min(ans, maxval*c*2) << endl;

    return 0;
}
