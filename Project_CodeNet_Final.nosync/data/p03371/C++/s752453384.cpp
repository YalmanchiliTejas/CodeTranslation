#include "bits/stdc++.h"
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long sum = 0;
    if (A + B > C * 2) {
        if (X < Y) {
            sum += min(X * C * 2 + (Y - X) * B, Y * C * 2);
        }
        else {
            sum += min(Y * C * 2 + (X - Y) * A, X * C * 2);
        }
    }
    else {
        sum += min(X * A + Y * B, max(X, Y) * C * 2);
    }

    cout << sum << endl;
}