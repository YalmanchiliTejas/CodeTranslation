#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
const int XY_MAX = pow(10, 5);
int main (void) {
    int A, B, C;
    int X, Y;

    cin >> A >> B >> C >> X >> Y;

    int ans = INT_MAX;
    for (int i = 0; i <= XY_MAX; i++) {
        ans = min(ans, 2 * C * i + max(0, X - i) * A + max(0, Y - i) * B);
    }

    cout << ans << endl;

    return 0;
}
