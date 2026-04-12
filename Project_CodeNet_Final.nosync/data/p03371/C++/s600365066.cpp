#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long sum = 0;
    if (2 * c < a + b) {
        sum = 1ll * min(x, y) * 2 * c;
        int val = min(x,y);
        x -= val;
        y -= val;
    }

    if (x > 0) {
        if (2 * c < a) {
            sum += (1ll * 2 * c * x);
        } else {
            sum += 1ll * a * x;
        }
    }

    if (y > 0) {
        if (2 * c < b) {
            sum += (1ll * 2 * c * y);
        } else {
            sum += 1ll * b * y;
        }
    }
    cout << sum;
    return 0;
}
