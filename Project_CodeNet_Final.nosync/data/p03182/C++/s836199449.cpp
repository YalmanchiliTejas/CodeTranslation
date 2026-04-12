#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 2e5 + 10;
int ans, n, m;
vector<pair<int, int>> event[maxn];

#define lc (v << 1)
#define rc (lc | 1)
#define tm (tl + tr >> 1)

int t[maxn << 2], lazy[maxn << 2];

void shift(int v)
{
    t[lc] += lazy[v];
    t[rc] += lazy[v];
    lazy[lc] += lazy[v];
    lazy[rc] += lazy[v];

    lazy[v] = 0;
}

void update(int l, int r, int x, int v = 1, int tl = 0, int tr = n - 1)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
        t[v] += x, lazy[v] += x;
    else
    {
        shift(v);
        update(l, min(r, tm), x, lc, tl, tm);
        update(max(l, tm + 1), r, x, rc, tm + 1, tr);
        t[v] = max(t[lc], t[rc]);
    }
}

int get(int l, int r, int v = 1, int tl = 0, int tr = n - 1)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[v];
    shift(v);
    return max(get(l, min(r, tm), lc, tl, tm), get(max(l, tm + 1), r, rc, tm + 1, tr));
}

signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0, l, r, w; i < m; i++)
        cin >> l >> r >> w, event[r - 1].push_back({l - 1, w});
    for (int i = 0; i < n; i++)
    {
        update(i, i, ans);
        for (auto u : event[i])
            update(u.first, i, u.second);
        ans = max(0ll, get(0, i));
    }

    cout << ans;

    return 0;
}
