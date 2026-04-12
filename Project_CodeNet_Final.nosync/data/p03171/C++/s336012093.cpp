#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define Repr(i, n, a) for (int i = (n); i >= (a); i--)
#define rep(i, n) Rep(i, 0, n)
#define repr(i, n) Repr(i, n, 0)
#define all(a) a.begin(), a.end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

int n;
vector<int> a;
int dp[3010][3010];
bool vis[3010][3010];

int solve(int p, int q)
{
    if (vis[p][q])
        return dp[p][q];
    vis[p][q] = true;
    bool turn = (n + q - p) & 1;
    if (p == q)
    {
        if (turn)
            return dp[p][q] = a[p];
        else
            return dp[p][q] = -a[p];
    }
    if (turn)
        dp[p][q] = max(solve(p + 1, q) + a[p], solve(p, q - 1) + a[q]);
    else
        dp[p][q] = min(solve(p + 1, q) - a[p], solve(p, q - 1) - a[q]);
    return dp[p][q];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    cout << solve(0, n - 1) << endl;
}