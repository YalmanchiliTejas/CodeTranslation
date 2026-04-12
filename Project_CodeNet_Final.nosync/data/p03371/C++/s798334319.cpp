//median 33min
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i, n, init) for (ll i = init; i < (n); i++)
#define repd(i, n, init) for (ll i = (n); i >= init; i--)
#define repm(i, m) for (auto i = m.begin(); i != m.end(); i++)

int main()
{
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll Ans = 0, m = 0;
    m = min(A + B, C * 2);
    Ans = m * min(X, Y);
    if (X == min(X, Y))
    {
        Y -= X;
        X = 0;
        m = min(B,C*2);
    }
    else
    {
        X -= Y;
        Y = 0;
        m = min(A,C*2);
    }
    Ans += X * m + Y * m;
    cout << Ans << endl;
    return 0;
}