#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, n) for (Int i = s; i < (Int)(n); i++)
#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
double EPS = 1e-10;
Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (c * 2 > a + b) {
        Int res = min(x, y) * (a + b);
        Int sub = min(x, y);
        x -= sub;
        y -= sub;
        if (c * 2 > a) {
            res += x * a;
        } else {
            res += x * c * 2;
        }
        if (c * 2 > b) {
            res += y * b;
        } else {
            res += y * c * 2;
        }
        dump(res);
        return 0;
    } else {
        Int res = min(x, y) * c * 2;
        Int sub = min(x, y);
        x -= sub;
        y -= sub;
        if (c * 2 > a) {
            res += x * a;
        } else {
            res += x * c * 2;
        }
        if (c * 2 > b) {
            res += y * b;
        } else {
            res += y * c * 2;
        }
        dump(res);
        return 0;
    }
    return 0;
}