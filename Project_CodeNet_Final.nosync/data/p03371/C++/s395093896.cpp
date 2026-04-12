#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int64_t sum = 0;
    if (A >= (2 * C) && B >= (2 * C)) {
        int64_t s = max(X, Y);
        sum += s * (2 * C);
    } else if ((A + B) >= 2 * C) {
        if (X > Y) {
            int64_t sa = X - Y;
            int64_t s = min(X, Y);
            sum += s * (2 * C);
            sum += min((sa * A), (sa * 2 * C));
        } else if (Y > X) {
            int64_t sa = Y - X;
            int64_t s = min(X, Y);
            sum += s * (2 * C);
            sum += min((sa * B), (sa * 2 * C));
        } else {
            int64_t s = min(X, Y);
            sum += s * (2 * C);
        }
    } else {
        sum = (A * X) + (B * Y);
    }

    cout << sum << endl;
    return 0;
}