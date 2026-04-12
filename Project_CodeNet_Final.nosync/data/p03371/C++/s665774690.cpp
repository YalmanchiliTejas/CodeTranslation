#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    c *= 2; // A,B1枚に必要な金額に直しておく
    int ans = a * x + b * y; // ABピザを買わない場合の値

    if (x > y) {
        ans = min({ans, c * y + a * (x - y), c * x});
    } else {
        ans = min({ans, c * x + b * (y - x), c * y});
    }

    cout << ans << endl;
    return 0;
}