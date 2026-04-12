#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define pll pair<ll, ll>
#define pii pair<int, int>
#define f first
#define se second
#define pb push_back
#define ft fflush(stdout)
 
 
using namespace std;
 
 
const int N = 3e3 + 123;
const int PLS = 3e5 + 123;
const int mod = 1e9 + 7;
const ll inf = 1e16;


ll n, a[N], dp[N][N][2];
bool vis[N][N][2];


void rec(int l, int r, int vl) {
    if (vis[l][r][vl])
        return;
    vis[l][r][vl] = 1;
    if (l == r) {
        if (vl == 0)
            dp[l][r][vl] = a[l];
        else
            dp[l][r][vl] = -a[l];
        return;
    }
    rec(l + 1, r, 1 - vl);
    rec(l, r - 1, 1 - vl);
    if (vl == 0)
        dp[l][r][vl] = max(a[l] + dp[l + 1][r][1 - vl], dp[l][r - 1][1 - vl] + a[r]);
    else
        dp[l][r][vl] = min(dp[l + 1][r][1 - vl] - a[l], dp[l][r - 1][1 - vl] - a[r]);
}


int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            dp[i][j][0] = dp[i][j][1] = -inf;
    rec(1, n, 0);
    cout << dp[1][n][0];
}