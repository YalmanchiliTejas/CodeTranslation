#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;

    if (A + B <= 2 * C) ans = A * X + B * Y;
    else {
        if (X < Y) ans = min(C * 2 * X + B * (Y - X), C * 2 * Y);
        else ans = min(C * 2 * Y + A * (X - Y), C * 2 * X);
    }

    cout << ans << endl;

    return 0;
}
