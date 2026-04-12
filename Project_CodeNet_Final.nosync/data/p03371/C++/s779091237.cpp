#include "bits/stdc++.h"
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int res = 0;
    while (x > 0 and y > 0 and a + b >= 2 * c) {
        res += 2 * c;
        x--, y--;
    }

    while (x > 0) {
        if (a < 2 * c) {
            res += a;
            x--;
        }
        else {
            res += 2 * c;
            x--;
            y--;
        }
    }

    while (y > 0) {
        if (b < 2 * c) {
            res += b;
            y--;
        }
        else
        {
            res += 2 * c;
            y--;
        }
    }

    printf("%d\n", res);
}