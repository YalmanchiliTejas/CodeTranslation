#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;

    if(a >= 2 * c && b >= 2 * c) {
        cout << 2 * max(x, y) * c << endl;
        return 0;
    }

    if(a + b >= 2 * c) {
        ans += 2 * min(x, y) * c;
        if(x > y) {
            if(a >= 2 * c)
                ans += 2 * c * (x - y);
            else
                ans += (x - y) * a;
        } else if(y > x) {
            if(b >= 2 * c)
                ans += 2 * c * (y - x);
            else
                ans += (y - x) * b;
        }
    } else {
        ans += a * x + b * y;
    }

    cout << ans << endl;
}