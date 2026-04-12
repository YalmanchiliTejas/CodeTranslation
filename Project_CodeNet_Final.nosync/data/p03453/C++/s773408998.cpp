#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e5 + 7;
const int M = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a >= M) a -= M;
    if (a < 0) a += M;
    return a;
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

const ll inf = 1e18;

vector <pair <int, int> > g[N];
ll d[N];
ll vd[N];

int prs(int x)
{
    int ans = mul(x, add(x, -1));
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    s--, t--;
    for (int i = 0; i < m; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        g[a].push_back({b, d});
        g[b].push_back({a, d});
    }
    set <pair <ll, int> > q;
    for (int i = 0; i < n; i++)
    {
        d[i] = inf;
        vd[i] = inf;
    }
    d[s] = 0;
    q.insert({d[s], s});
    while (!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto c : g[v])
        {
            int to = c.first;
            int len = c.second;
            if (d[to] > d[v] + len)
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    vd[t] = 0;
    q.insert({vd[t], t});
    while (!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto c : g[v])
        {
            int to = c.first;
            int len = c.second;
            if (vd[to] > vd[v] + len)
            {
                q.erase({vd[to], to});
                vd[to] = vd[v] + len;
                q.insert({vd[to], to});
            }
        }
    }
    vector <int> srt(n);
    vector <int> prt(n);
    for (int i = 0; i < n; i++) srt[i] = i, prt[i] = i;
    sort(srt.begin(), srt.end(), [] (int a, int b)
    {
        return d[a] < d[b];
    });
    sort(prt.begin(), prt.end(), [] (int a, int b)
    {
        return vd[a] < vd[b];
    });
    vector <int> cnt(n);
    vector <int> pnt(n);
    cnt[s] = 1;
    for (int i : srt)
    {
        for (auto x : g[i])
        {
            int to = x.first, len = x.second;
            if (d[to] == d[i] + len)
            {
                cnt[to] = add(cnt[to], cnt[i]);
            }
        }
    }
    pnt[t] = 1;
    for (int i : prt)
    {
        for (auto x : g[i])
        {
            int to = x.first, len = x.second;
            if (vd[to] == vd[i] + len)
            {
                pnt[to] = add(pnt[to], pnt[i]);
            }
        }
    }
    int ans = prs(cnt[t]);
    for (int i = 0; i < n; i++)
    {
        if (d[i] + vd[i] == d[t])
        {
            if (d[i] == vd[i])
            {
                ans = add(ans, -prs(mul(cnt[i], pnt[i])));                
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto x : g[i])
        {
            int to = x.first;
            int len = x.second;
            if (d[t] == d[i] + len + vd[to])
            {
                ll l1 = d[i];
                ll r1 = d[i] + len;
                ll l2 = vd[to];
                ll r2 = vd[to] + len;
                if (max(l1, l2) < min(r1, r2))
                {
                    ans = add(ans, -prs(mul(cnt[i], pnt[to])));
                }
            }
        }
    }
    cout << ans << '\n';
}
