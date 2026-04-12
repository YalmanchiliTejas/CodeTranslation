#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#define pri(a) cout << a << endl;
using namespace std;
typedef int64_t Int;
typedef uint64_t uInt;
const double pi = M_PI;

int main() {
    Int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if (a + b > 2 * c) {
        if (x < y) {
            if (b < 2 * c) {
                pri(b * (y - x) + 2 * c * x);
            } else {
                pri(2 * c * y);
            }
        } else if (x > y) {
            if (a < 2 * c) {
                pri(a * (x - y) + 2 * c * y);
            } else {
                pri(2 * c * x);
            }
        } else {
            pri(2 * c * x);
        }

    } else {
        pri(a * x + b * y);
    }
}
