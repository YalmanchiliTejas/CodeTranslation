#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
using Int = long long;
int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int money = 0;
    if ((A + B) < 2*C) {
        cout << A * X + B * Y << endl;
    } else {
        int m = min(X, Y);
        money = 2 * C * m;
        X -= m;
        Y -= m;
        if (X) {
            if (A > 2*C) money += 2 * C * X;
            else money += A * X;
        }
        if (Y) {
            if (B > 2*C) money += 2 * C * Y;
            else money += B * Y;
        }
        cout << money << endl;
    }
    return 0;
}