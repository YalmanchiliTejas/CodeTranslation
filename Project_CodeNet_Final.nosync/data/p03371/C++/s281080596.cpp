#include <bits/stdc++.h>

#define INF 1e9
using namespace std;
typedef long long ll;

int main() {

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = INF;

    for (int i = 0; i <= 100000; ++i) {
        ans = min(ans, 2 * c * i + max(x - i, 0) * a + max(y - i, 0) * b);
    }

    cout << ans << endl;
}