
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 3e3;
int n, a[nsz + 5];
num dp[nsz + 5][nsz + 5][2], ans;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    cont (i, n) {
        cin >> a[i];
        dp[i][i][1] = a[i];
    }
    circ (len, 2, n) {
        for (int l = 1, r = len; r <= n; ++l, ++r) {
            if (len & 1) {
                dp[l][r][1] = max(dp[l + 1][r][0] + a[l], dp[l][r - 1][0] + a[r]);
            } else {
                dp[l][r][0] = min(dp[l + 1][r][1] - a[l], dp[l][r - 1][1] - a[r]);
            }
        }
    }
    ans = (n & 1) ? dp[1][n][n & 1] : -dp[1][n][n & 1];
    cout << ans << ln;
}
