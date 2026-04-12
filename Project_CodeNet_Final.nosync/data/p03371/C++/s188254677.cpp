#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = a * x + b * y;
    for (int i = 1; i <= max(x, y); i++) {
        int comb = c * 2 * i;
        int xx = max(0, x - i);
        int yy = max(0, y - i);
        comb += xx * a + yy * b;
        ans = min(ans, comb);
    }
    cout << ans << endl;
    return 0;
}