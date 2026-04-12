#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int x, y; cin >> x >> y;
    if (c * 2 < a + b) {
        if (x > y) {
            cout << c * 2 * y + (x - y) * min(2 * c, a) << endl;
        } else {
            cout << c * 2 * x + (y - x) * min(c * 2, b) << endl;
        }
    } else {
        cout << a * x + b * y << endl;
    }
    return 0;
}
