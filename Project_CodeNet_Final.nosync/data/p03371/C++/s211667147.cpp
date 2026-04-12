#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    if (A + B < 2 * C)
    {
        cout << A * X + B * Y << endl;
        return 0;
    }

    int ans = min(X, Y);
    X -= ans;
    Y -= ans;

    ans *= 2 * C;
    if (X > 0)
    {
        if (A < 2 * C)
        {
            ans += A * X;
        }
        else
        {
            ans += 2 * C * X;
        }
    }
    else if (Y > 0)
    {
        if (B < 2 * C)
        {
            ans += B * Y;
        }
        else
        {
            ans += 2 * C * Y;
        }
    }
    cout << ans << endl;
}
