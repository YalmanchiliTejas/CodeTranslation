#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct seg
{
    struct node
    {
        ll tag, mx;
    };
    int n;
    vector<node> t;
    void init(int _n)
    {
        n = _n;
        t.assign(2 * n - 1, {0, 0});
    }
    void dat(int o, ll v)
    {
        t[o].tag += v;
        t[o].mx += v;
    }
    void push(int o, int z)
    {
        if (t[o].tag) {
            dat(o + 1, t[o].tag);
            dat(z, t[o].tag);
            t[o].tag = 0;
        }
    }
    void pull(int o, int z)
    {
        t[o].mx = max(t[o + 1].mx, t[z].mx);
    }
    void add(int i, int j, ll v, int o, int l, int r)
    {
        if (j <= l || r <= i)
            return;
        if (i <= l && r <= j) {
            dat(o, v);
            return;
        }
        int m = l + (r - l) / 2;
        int z = o + (r - l) / 2 * 2;
        push(o, z);
        add(i, j, v, o + 1, l, m);
        add(i, j, v, z, m, r);
        pull(o, z);
    }
    ll qry(int i, int j, int o, int l, int r)
    {
        if (j <= l || r <= i)
            return LLONG_MIN;
        if (i <= l && r <= j)
            return t[o].mx;
        int m = l + (r - l) / 2;
        int z = o + (r - l) / 2 * 2;
        push(o, z);
        ll ret = qry(i, j, o + 1, l, m);
        return max(ret, qry(i, j, z, m, r));
    }
    void add(int l ,int r, ll v)
    {
        add(l - 1, r, v, 0, 0, n);
    }
    ll qry(int l, int r)
    {
        return qry(l - 1, r, 0, 0, n);
    }
} t;
const int N = 2e5 + 87;
vector<pair<int,int>> ev[N];
ll dp[N];
int main()
{
    int n, m;
    cin >> n >> m;
    t.init(n);
    for (int i = 0; i < m; ++i) {
        int l, r, a;
        cin >> l >> r >> a;
        ev[r].emplace_back(l, a);
    }
    for (int i = 1; i <= n; ++i) {
        for (const auto & p : ev[i])
            t.add(p.first, i, p.second);
        dp[i] = max(0ll, t.qry(1, i));
        t.add(i + 1, i + 1, dp[i]);
    }
    cout << dp[n] << endl;
}
