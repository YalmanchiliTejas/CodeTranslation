#include <iostream>

int main() {
    using namespace std;
    int a, b, c;
    int x, y;
    int cost = 0;
    cin >> a >> b >> c >> x >> y;
    if (2 * c < a + b) {
        int minxy = min(x, y);
        cost += minxy * 2 * c;
        x -= minxy;
        y -= minxy;
    }
    if (2 * c < a && x > 0) {
        cost += x * 2 * c;
        y -= x;
        x = 0;
    }
    if (2 * c < b && y > 0) {
        cost += y * 2 * c;
        x -= y;
        y = 0;
    }
    if (x > 0) {
        cost += x * a;
        x = 0;
    }
    if (y > 0) {
        cost += y * b;
        y = 0;
    }
    cout << cost << endl;
}