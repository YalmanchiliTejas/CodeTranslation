#include <bits/stdc++.h>
using namespace std;

#define ENGZ ios::sync_with_stdio(0);cin.tie(0);ios_base::sync_with_stdio(0);
#define sfi(x) scanf("%d" , &x)
#define sfi2(x, y) scanf("%d%d" , &x,&y)
#define sfl2(x, y) scanf("%I64d%I64d" , &x,&y)
#define sfl(x) scanf("%I64d" , &x)
#define sfl3(x, y, z) scanf("%I64d%I64d%I64d", &x, &y, &z)
#define sfd(x) scanf("%lf", &x)
#define sfd2(x, y) scanf("%lf", &x, &y)
#define sfc(x) scanf("%c", &x)
#define testv(x) cerr << x << ' '
#define wtf(s) freopen((s), "w", stdout)
#define rff(s) freopen((s), "r", stdin)
#define test cerr << "here"
#define mod 1000000007
#define pi (2*acos(0))
typedef long double ld;
typedef long long ll;

int n;
ll a[3003], dp[3003][3003][2];
ll solve(int l, int r, int p)
{
    if (l > r)
        return 0;
    if (dp[l][r][p] != -1)
        return dp[l][r][p];
    if (p)
        return dp[l][r][p] = max(solve(l + 1, r, !p) + a[l], solve(l, r - 1, !p) + a[r]);
    else
        return dp[l][r][p] = min(solve(l + 1, r, !p) - a[l], solve(l, r - 1, !p) - a[r]);
}

int main()
{
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0, n - 1, 1);
    return 0;
}