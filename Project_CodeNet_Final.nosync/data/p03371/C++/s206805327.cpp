#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;

int main()
{
    int32_t A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int32_t ans = INT32_MAX;
    for (int i = 0; i <= 2 * max(X, Y); i += 2)
    {
        int half = i / 2;
        int x = max(X - half, 0);
        int y = max(Y - half, 0);
        ans = min(ans, A * x + B * y + C * i);
    }
    cout << ans << endl;
}