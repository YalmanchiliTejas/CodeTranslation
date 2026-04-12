#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1LL<<60;
const int MOD = (int)1e9 + 7;


signed main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int sum = 0;
    if (a + b > 2 * c) {
        int num_c = min(x, y);
        sum += min(max(x, y) * c * 2, num_c * c * 2 + (x - num_c) * a + (y - num_c) * b);
    }
    else {
        sum += a * x + b * y;
    }
    cout << sum << "\n";
}