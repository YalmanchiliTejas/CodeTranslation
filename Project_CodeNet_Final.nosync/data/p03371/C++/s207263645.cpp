#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans = 0;
    if ((A + B) / 2 >= C)
    {
        long long min_num = min(X, Y);
        ans += min_num * 2 * C;
        X -= min_num;
        Y -= min_num;
        if ((A <= 2 * C) || (B <= 2 * C))
        {

            ans += (min(A, 2*C) * X + min(B,2*C) * Y);
        }
        else
        {
            ans += max(X, Y) * 2 * C;
        }
    }
    else
    {
        ans += (A * X + B * Y);
    }
    cout << ans << endl;
}