#include <iostream>
#include <cmath>

#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <array>

using namespace std;


int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (2 * c > a + b) {
        cout << a * x + b * y << endl;
    } else {
        int common = min(x, y);
        int yen = common * c * 2;
        int diff = max(x, y) - common;
        if (x > y) {
            yen += min(diff * a, diff * 2 * c);
        } else {
            yen += min(diff * b, diff * 2 * c);
        }
        cout << yen << endl;
    }

}
