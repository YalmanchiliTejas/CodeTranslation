#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define MAXN 3123

int n;
ll vals[MAXN];
pll dp[MAXN][MAXN][2];
int vis[MAXN][MAXN][2];

pll solve(int l, int r, int t)
{
    if (l > r)
        return {0, 0};

    if (vis[l][r][t])
        return dp[l][r][t];
    vis[l][r][t] = 1;
    
    if (t)
    {
        pll rec1 = solve(l + 1, r, !t);
        rec1.se += vals[l];
        pll rec2 = solve(l, r - 1, !t);
        rec2.se += vals[r];

        if (rec1.fi - rec1.se < rec2.fi - rec2.se)
            return dp[l][r][t] = rec1;
        else
            return dp[l][r][t] = rec2;
    }
    else
    {
        pll rec1 = solve(l + 1, r, !t);
        rec1.fi += vals[l];
        pll rec2 = solve(l, r - 1, !t);
        rec2.fi += vals[r];

        if (rec1.fi - rec1.se > rec2.fi - rec2.se)
            return dp[l][r][t] = rec1;
        else
            return dp[l][r][t] = rec2;
    }
    
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &vals[i]);
    }
    
    printf("%lld\n", solve(0, n - 1, 0).fi - solve(0, n - 1, 0).se);
}