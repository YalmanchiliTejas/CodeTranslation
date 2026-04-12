#ifdef loc
    #include "loc_debug.h"
#else
    #include <bits/stdc++.h>
    #define pr(...)
    #define pra(a,n)
    #define praa(a,n,m)
    #define prl()
#endif
using namespace std;

typedef long long ll;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define sz(a) int(a.size())
const int N = 3005;
ll a[N], f[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        f[i][i] = a[i];
    }
    rep(l, 2, n + 1) {
        rep(j, 0, n - l + 1) {
            f[j][j + l - 1] = max(a[j] - f[j + 1][j + l - 1],
                                  a[j + l - 1] - f[j][j + l - 2]);
            pr(j, j + l - 1, f[j][j + l - 1]);
        }
    }
    cout << f[0][n - 1] << endl;
}