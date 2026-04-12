#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
typedef long long lint;
#define int lint
const int INF = 1e7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repi(i, k, n) for (int i = (k); i < (int)(n); ++i)
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
int n, x;
vi len(51, INF);
vi pa(51, INF);
int length(int n)
{
    if (len[n] != INF)
    {
        return len[n];
    }
    if (n == 0)
    {
        return len[n] = 1;
    }
    return len[n] = 2 * length(n - 1) + 3;
}
int pati(int n)
{
    if (pa[n] != INF)
    {
        return pa[n];
    }
    if (n == 0)
    {
        return pa[n] = 1;
    }
    return pa[n] = 1 + pati(n - 1) * 2;
}
int solve(int n, int x)
{
    if (x == length(n))
    {
        return pati(n);
    }
    if (x == 1 || x == 0)
    {
        return 0;
    }
    if (x == length(n) / 2 + 1)
    {
        return solve(n - 1, length(n - 1)) + 1;
    }
    else if (x > length(n) / 2 + 1)
    {
        return +solve(n - 1, x - length(n) / 2 - 1) + solve(n - 1, length(n - 1)) + 1;
    }
    else
    {
        return solve(n - 1, x - 1);
    }
}

signed main()
{
    cin >> n >> x;
    int ans = solve(n, x);
    cout << ans << endl;
    return 0;
}