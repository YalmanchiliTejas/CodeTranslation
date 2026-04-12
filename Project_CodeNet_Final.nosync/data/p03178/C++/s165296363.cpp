#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Nmax = 1e4 + 5;
const int mod = 1e9 + 7;

int dp[Nmax][100][2];
int n,m;

string s;

void add(int &a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
}

int solve(int i, int cur, bool smlr)
{
    int &res = dp[i][cur][smlr];
    if (i > n) return !cur;
    if (res != -1) return res;
    res = 0;
    int lim = s[i] - '0';
    if (smlr) lim = 9;
    for (int d = 0; d <= lim; d++)
    {
        int nxt = (cur + d) % m;
        add(res, solve(i + 1, nxt, smlr | (d < s[i] - '0')));
    }
    return res;
}

signed main()
{
    //freopen("file.inp","r",stdin);
    cin >> s >> m;
    n = s.size();
    s = ' ' + s;
    memset(dp, -1, sizeof(dp));
    cout << (solve(1, 0, 0) - 1 + mod) % mod;
    return 0;
}
