#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 1e18;
    for (int C = 0; C <= max(2*x,2*y); C++) {
        int A = max(x-C/2,0);
        int B = max(y-C/2,0);
        ll cost = a*A + b*B + c*C;
        ans = min(ans,cost);
    }
    cout << ans << endl;
}