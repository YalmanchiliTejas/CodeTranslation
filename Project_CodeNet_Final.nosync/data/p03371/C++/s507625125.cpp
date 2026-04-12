#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int a, b, c, x, y;

int main() {
    cin >> a >> b >> c >> x >> y;
    if (c * 2 <= a + b) {
        int ans = 0;
        int m = min(x, y);
        x -= m;
        y -= m;
        ans += m * 2 * c;
        ans += min(c * 2, a) * x;
        ans += min(c * 2, b) * y;
        cout << ans << endl;
    } else {
        cout << a * x + b * y << endl;
    }
    return 0;
}
