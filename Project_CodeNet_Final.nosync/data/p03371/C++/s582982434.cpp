#include <iostream>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    if (2 * C < A + B)
    {
        int m = min(X, Y);
        ans += C * m * 2;
        X -= m;
        Y -= m;

        if ((X == 0 && B < 2 * C) || (Y == 0 && A < 2 * C))
        {
            ans += X * A + Y * B;
        }
        else
        {
            ans += (X + Y) * 2 * C;
        }
    }
    else
    {
        ans += X * A + Y * B;
    }

    cout << ans << endl;

    return 0;
}