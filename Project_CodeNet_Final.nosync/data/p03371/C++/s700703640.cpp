#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    Int res = 0;
    if (a + b >= c * 2) {
        res += min(x, y) * c * 2;
        Int sub = min(x, y);
        x -= sub;
        y -= sub;
        if (x > 0) {
            res += x * min(a, c * 2);
        }
        else {
            res += y * min(b, c * 2);
        }
    }
    else {
        if (c * 2 < a) {
            res += x * (c * 2);
            y = max((Int)0, y - x);
            res += y * b;
        }  
        else if (c * 2 < b) {
            res += y * (c * 2);
            x = max((Int)0, x - y);
            res += x * a;
        }
        else {
            res += a * x + b * y;
        }
    }
    dump(res);
    return 0;
}
