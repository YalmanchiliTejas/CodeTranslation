
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
const num inf = 0x3f3f3f3f3f3f3f3f;
int n, a[nsz + 5];
num dp[nsz + 5][nsz + 5][2];

num dfs(int l, int r, int me) {
    if (dp[l][r][me] != -inf)  return dp[l][r][me];
    if (l + r == n)  return 0;
    int i = l + 1, j = n - r;
    if (me == 0) {
        return dp[l][r][me] = max(dfs(l + 1, r, !me) + a[i], dfs(l, r + 1, !me) + a[j]);
    } else {
        return dp[l][r][me] = min(dfs(l + 1, r, !me) - a[i], dfs(l, r + 1, !me) - a[j]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    cont (i, n) {
        cin >> a[i];
    }
    fill(dp[0][0], dp[0][0] + sizeof(dp) / sizeof(num), -inf);
    cout << dfs(0, 0, 0) << ln;
}