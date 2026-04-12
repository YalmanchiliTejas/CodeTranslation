#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)    FOR (i,0,n)
#define ALL(f,x,...) ([&](decltype((x)) ALL) {                          \
            return (f)(begin(ALL), end(ALL), ## __VA_ARGS__); })(x)

#define __STDC_FORMAT_MACROS
#define p64 PRId64

using namespace std;
using ll = int64_t;

int main()
{
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = 0;
    if (A <= C && B <= C)
    {
        cout << A * X + B * Y << endl;
    }
//    else if (A <= C && C < B)
//    {
//        ll x = max((ll)0, (X - Y));
//        ans = min(A * x + C * 2 * Y, A * X + B * Y);
//        cout << ans << endl;
//    }
//    else if (C < A && B <= C)
//    {
//        ll y = max((ll)0, (Y - X));
//        ans = min(C * 2 * X + B * y, A * X + B * Y);
//        cout << ans << endl;
//    }
    else
    {
        ll xy = max(X, Y);
        ll xymn = min(X, Y);
        ans = min(C * 2 * xy, A * X + B * Y);
        ans = min(ans,
                  C * 2 * xymn
                  + A * max((ll)0, X - xymn)
                  + B * max((ll)0, Y - xymn));
        cout << ans << endl;
    }

    return 0;
}
