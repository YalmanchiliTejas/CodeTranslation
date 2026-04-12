#include <iostream>

using namespace std;

int main()
{
    int A, B, C, X, Y, ans;

    cin >> A >> B >> C >> X >> Y;

    if (A + B < C * 2)
    {
        ans = A * X + B * Y;
    }
    else
    {
        int min = X < Y ? X : Y;
        int max = X > Y ? X : Y;
        int maxP = X > Y ? A : B;

        ans = min * 2 * C;

        if (maxP < C * 2)
            ans += (max - min) * maxP;
        else
            ans += (max - min) * 2 * C;
    }

    cout << ans << endl;

    return 0;
}