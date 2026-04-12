#include <bits/stdc++.h>
#define PI M_PI
#define REP(i, n) for (int i=0; i<n; i++)
#define print(x) cout << x << endl;
#define debug(x) cout << #x << " = " << endl;

typedef long long ll;

using namespace std;

void chmin(ll &x, ll &y) {
    x = min(x, y);
}

void solve()
{
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
   
    ll ans = 1001001001001LL;
    ll tmp = A * X + B * Y;
    chmin(ans, tmp);

    tmp = 2 * C * max(X, Y);
    chmin(ans, tmp);

    if (X >= Y) {
        tmp = 0;
        tmp += 2LL * C * min(X, Y);
        tmp += A * (X - Y);
        chmin(ans, tmp);
    } else {
        tmp = 0;
        tmp += 2LL * C * min(X, Y);
        tmp += B * (Y - X);
        chmin(ans, tmp);
    }
    print(ans);

}

int main()
{
    solve();

    return 0;
}
