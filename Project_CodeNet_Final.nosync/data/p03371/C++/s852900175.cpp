#include <iostream>
using namespace std;

int main() {
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    long long ans = 1LL << 60;
    for (long long i = 0; i <= max(x, y); i++) {
        ans = min(ans, 2 * c * i + max(0LL, x - i) * a + max(0LL, y - i) * b);
    }

    cout << ans << endl;
    return 0;
}