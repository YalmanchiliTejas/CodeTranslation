#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    c *= 2;
    int n = max(x, y), price, ans = 1e9;
    for (int i = 0; i <= n; i++) {
        price = c * i + a * max(x - i, 0) + b * max(y - i, 0);
        ans = min(ans, price);
    }
    cout << ans << endl;
}