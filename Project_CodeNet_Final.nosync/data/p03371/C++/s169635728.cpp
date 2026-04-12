// https://atcoder.jp/contests/abc095/tasks/arc096_a

#include <algorithm>
#include <cmath>
#include <iostream>
#include <regex>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

#define EPS (1e-7)
#define INF (1e9)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOREACH(x, a) for (auto &(x) : (a))
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

// long gcd(long a, long b) { return b ? gcd(b, a % b) : a; }
// long lcm(long a, long b) { return a * b / gcd(a, b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, x, y, ans;
    cin >> a >> b >> c >> x >> y;
    // Cセットが高ければ、別々に買う
    if (a + b < 2 * c) {
        ans = a * x + b * y;
    } else {
        if (x > y) {
            ans = (x - y) * a + 2 * c * y;
        } else {
            ans = (y - x) * b + 2 * c * x;
        }
        int ans2 = max(x, y) * 2 * c;
        ans = min(ans, ans2);
    }
    cout << ans << endl;

    return 0;
}
