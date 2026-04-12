#include <bits/stdc++.h>
#define MAX_N 10000
#define INF 1e9

using namespace std;

typedef int long long ll;
typedef int long l;
typedef pair<int, int> Pii;
const ll MOD = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    c *= 2;
    int ans = 0;
    if (y >= x) {
        int tmp;
        tmp = x;
        x = y;
        y = tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    // xの方が大きい
    if (a + b > c) {
        ans += c * y;
        x -= y;
        y = 0;
        if (a > c) {
            ans += c * x;
        } else {
            ans += a * x;
        }
    } else {
        ans += a * x + b * y;
    }
    cout << ans << endl;
    return 0;
}