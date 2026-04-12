#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int keta(ll A)
{
        int cnt = 0;
        while (A)
        {
                cnt++;
                A /= 10;
        }
        return cnt;
}

int main()
{
        int A, B, C, X, Y;
        cin >> A >> B >> C >> X >> Y;
        int ans = A * X + B * Y;
        ans = min(ans, C * max(X, Y) * 2);
        if (X > Y)
        {
                ans = min(ans, 2 * C * Y +  A* (X - Y));
        }
        else
        {
                ans = min(ans, 2 * C * X + B * (-X + Y));
        }
        ans = min(ans, C * max(X, Y) * 2);

        cout << ans << endl;
        return 0;
}
