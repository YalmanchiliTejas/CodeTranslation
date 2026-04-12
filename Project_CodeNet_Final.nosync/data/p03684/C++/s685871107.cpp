#define taskname "test"

#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)x.size()
#define fi first
#define se second

typedef long long lli;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;

int n;
pii towns[maxn];

vector<int> vx, vy;

vector<pair<int, pii>> edges;

int lab[maxn];

void read_input()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        towns[i] = pii(x, y);
        vx.push_back(x);
        vy.push_back(y);
    }
}

int find_set(int u)
{
    return lab[u] < 0 ? u : lab[u] = find_set(lab[u]);
}

void union_sets(int u, int v)
{
    u = find_set(u); v = find_set(v);
    if(u == v) return;
    if(lab[u] < lab[v]) swap(u, v);
    lab[v] += lab[u];
    lab[u] = v;
}

void init()
{
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());

    fill(begin(lab), end(lab), -1);

    for(int i = 1; i <= n; ++i)
    {
        int u = lower_bound(vx.begin(), vx.end(), towns[i].fi) - vx.begin();
        int v = lower_bound(vy.begin(), vy.end(), towns[i].se) - vy.begin() + sz(vx);
        union_sets(u, v);
    }

    for(int i = 1; i < sz(vx); ++i)
    {
        int cost = vx[i] - vx[i - 1];
        edges.push_back(make_pair(cost, pii(i - 1, i)));
    }

    for(int i = 1; i < sz(vy); ++i)
    {
        int cost = vy[i] - vy[i - 1];
        edges.push_back(make_pair(cost, pii(i - 1 + sz(vx), i + sz(vx))));
    }

    sort(edges.begin(), edges.end());
}

void solve()
{
    lli ans = 0;
    for(auto&e: edges)
    {
        int cost = e.fi;
        int u = e.se.fi, v = e.se.se;
        u = find_set(u); v = find_set(v);
        if(u != v)
        {
            ans += cost;
            union_sets(u, v);
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    read_input();
    init();
    solve();
}

