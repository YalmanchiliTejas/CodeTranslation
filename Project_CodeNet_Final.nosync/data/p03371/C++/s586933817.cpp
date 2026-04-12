#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;
typedef int64_t Int;
typedef uint64_t uInt;
const double pi = M_PI;

int main() {
    Int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    Int ans = INT64_MAX, count = max(x, y);

    for (Int i = 0; i < count + 1; i++) {
        ans = min(ans, 2 * c * i + a * max((Int)0, x - i) + b * max((Int)0, y - i));
    }

    cout << ans << endl;
}
