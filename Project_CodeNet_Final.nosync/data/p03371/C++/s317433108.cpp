#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int a, b, c, x, y, ans = INF;
    cin >> a >> b >> c >> x >> y;
    for (int i = 0; i <= 2 * max(x, y); ++i) {
        ans = min(ans, c * i + a * max(0, x - i / 2) + b * max(0, y - i / 2));
    }
    cout << ans << endl;

    return 0;
}