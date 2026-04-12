#include <bits/stdc++.h>
using namespace std;

int A, B, C, X, Y;

main()
{
    int total = 0;
    cin >> A >> B >> C >> X >> Y;
    if (A + B > 2 * C) {
        total += min(X, Y) * 2 * C;
        if (X > Y) {
            total += (X - Y) * A;
        } else {
            total += (Y - X) * B;
        }
        if (total > max(X, Y) * 2 * C) {
            total = max(X, Y) * 2 * C;
        }
    } else {
        total += X * A + Y * B;
    }
    cout << total << endl;
}