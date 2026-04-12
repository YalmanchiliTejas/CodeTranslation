#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = 0;
    if (2*C < A+B) {
        ans += min(X, Y) * C * 2;
        if (X > Y) {
            ans += (X-Y) * min(A, C*2);
        } else {
            ans += (Y-X) * min(B, C*2);
        }
    } else {
        ans += X * A;
        ans += Y * B;
    }

    cout << ans << endl;
    return 0;
}