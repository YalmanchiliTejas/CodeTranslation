#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int sum = 0;
    if (2 * C < A + B ) {
        int nC = min(X, Y) * 2;
        sum += nC * C;
        X = max<int>(X - nC / 2, 0);
        Y = max<int>(Y - nC / 2, 0);
    }
    if (2 * C < A) {
        int nC = X * 2;
        sum += nC * C;
        X = max<int>(X - nC / 2, 0);
        Y = max<int>(Y - nC / 2, 0);
    }
    if (2 * C < B) {
        int nC = Y * 2;
        sum += nC * C;
        X = max<int>(X - nC / 2, 0);
        Y = max<int>(Y - nC / 2, 0);
    }
    sum += X * A + Y * B;

    cout << sum << "\n";

}
