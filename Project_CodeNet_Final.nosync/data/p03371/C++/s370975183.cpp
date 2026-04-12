#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans1 = min(a + b, 2 * c) * min(x, y);
    int ans2 = 0;
    if (x > y) {
        ans2 = min(a, 2 * c) * (x - y);
    } else {
        ans2 = min(b, 2 * c) * (y - x);
    }
    cout << ans1 + ans2 << endl;
    return 0;
}
