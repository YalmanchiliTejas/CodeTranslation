#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    long long sum = 0;

    for (int i = y + 1; i <= x; ++i) {
        sum = sum + (i - y) * (x / i);
        if (x % i - y >= 0) {
            sum = sum + 1 + x % i - y;
        }
    }

    if (y == 0) {
        sum = sum - x;
    }

    cout << sum << endl;
    return 0;
}
