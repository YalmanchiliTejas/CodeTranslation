#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    if (A + B <= 2 * C)
    {
        ans += A * X + B * Y;
    }
    else
    {
        if (X <= Y)
        {
            ans += 2 * C * X + min(B, 2 * C) * (Y - X);
        }
        else
        {
            ans += 2 * C * Y + min(A, 2 * C) * (X - Y);
        }
    }

    cout << ans << endl;
}
