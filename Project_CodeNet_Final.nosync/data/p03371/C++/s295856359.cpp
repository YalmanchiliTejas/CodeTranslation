#include <iostream>


using namespace std;


int main()
{
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    if (A + B <= C * 2) {
        cout << A * X + B * Y << endl;
        return 0;
    }

    long long ans = 0;
    if (X >= Y) {
        X -= Y;
        ans += Y * 2 * C;
        if (A > C * 2)
            ans += X * 2 * C;
        else
            ans += X * A;
    } else {
        Y -= X;
        ans += X * 2 * C;
        if (B > C * 2)
            ans += Y * 2 * C;
        else
            ans += Y * B;
    }
    cout << ans << endl;
}
