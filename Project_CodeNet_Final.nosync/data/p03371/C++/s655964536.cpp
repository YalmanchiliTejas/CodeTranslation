
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const double PI = acos(-1);
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9 + 7;

#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) begin(a), end(a)

int main(void) {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = INF;
    int lim = max(X, Y) * 2 + 1;
    REP(c, lim) {
        int a = X - c / 2;
        a = max(a, 0);
        int b = Y - c / 2;
        b = max(b, 0);
        // cout << a << " " << b << " " << c << endl;
        ans = min(ans, (ll)(A * a + B * b + C * c));
    }
    cout << ans << endl;
    return 0;
}