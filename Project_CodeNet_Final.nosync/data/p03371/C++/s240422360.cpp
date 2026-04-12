#include <iostream>

using namespace std;

int main(void) {
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long price = 0;
    if (A + B >= 2 * C) {
        price += min(X, Y) * 2 * C;
    } else {
        price += min(X, Y) * (A + B);
    }

    if (X >= Y) {
        X -= Y;
        if (A >= 2 * C) {
            price += X * 2 * C;
        } else {
            price += X * A;
        }
    } else {
        Y -= X;
        if (B >= 2 * C) {
            price += Y * 2 * C;
        } else {
            price += Y * B;
        }
    }

    cout << price << endl;
    return 0;
}