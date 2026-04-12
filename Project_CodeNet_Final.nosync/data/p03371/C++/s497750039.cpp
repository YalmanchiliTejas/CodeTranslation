#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int a, b, c;
    int x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    int xyMin = min(x, y);
    if (a + b > 2 * c) {
        ans += xyMin * 2 * c;
    } else {
        ans += xyMin * a + xyMin * b;
    }
    if (x > y) {
        if (a > 2 * c) {
            ans += (x - y) * 2 * c;
        } else {
            ans += (x - y) * a;
        }
    } else {
        if (b > 2 * c) {
            ans += (y - x) * 2 * c;
        } else {
            ans += (y - x) * b;
        }
    }
    cout << ans << endl;
}