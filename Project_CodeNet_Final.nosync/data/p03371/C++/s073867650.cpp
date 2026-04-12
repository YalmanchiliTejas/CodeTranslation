#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char* LF = "\n";
namespace{struct _{_(){
    cin.tie(0);
    ios::sync_with_stdio(false);
}}a;}

signed main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans1 = A * X + B * Y;
    ll ans = 0;
    ll cx = 0, cy = 0;

    while (cx < X && cy < Y) {
        ans += 2 * C;
        cx++;
        cy++;
    }

    if (cx == X) {
        cx = cy;
        X = Y;
        A = B;
    }

    while (cx < X) {
        if (A < 2 * C) {
            ans += A;
            cx++;
        }
        else {
            ans += 2 * C;
            cx++;
        }
    }

    cout << min(ans, ans1) << LF;

    return 0;
}
