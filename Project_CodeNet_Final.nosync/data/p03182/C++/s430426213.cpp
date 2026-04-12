#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int l, r, x;
};

int n, m;
ban a[N];

vector<int> v[N];

long long t[N * 4];
long long laz[N * 4];

void shi(int pos)
{
    t[pos * 2] += laz[pos];
    laz[pos * 2] += laz[pos];
    t[pos * 2 + 1] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, long long y, int pos)
{
    if (tl == l && tr == r)
    {
        t[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, y, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, y, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, y, pos * 2);
        ubd(m + 1, tr, m + 1, r, y, pos * 2 + 1);
    }
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

long long qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return max(qry(tl, m, l, m, pos * 2),
     qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

long long dp[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].x);
    }
    for (int i = 1; i <= m; ++i)
    {
        v[a[i].l].push_back(i);
        v[a[i].r + 1].push_back(-i);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j];
            if (x > 0)
            {
                ubd(0, n, 0, a[x].l - 1, a[x].x, 1);
            }
            else
            {
                ubd(0, n, 0, a[-x].l - 1, -a[-x].x, 1);
            }
        }
        dp[i] = qry(0, n, 0, i - 1, 1);
        ubd(0, n, i, i, dp[i], 1);
    }
    long long ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
