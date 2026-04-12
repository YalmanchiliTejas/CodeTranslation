#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1e5 + 15;
const int INF = 1e9;
const long double eps = 1e-9;
const int MOD = 1e9 + 7;

int n, m;
int S, T;
vector <pair<int, int > > e[MaxN];
vector <int> v[MaxN], vr[MaxN];

long long d[MaxN];

long long dps[MaxN];
long long dpt[MaxN];

bool used[MaxN];

set<pair<long long, int> > s;

void dj()
{
    for(int i = 1; i <= n; ++i)
        d[i] = 1e18;

    s.insert(make_pair(0, S));
    d[S] = 0;

    while(!s.empty())
    {
        int x = s.begin() -> second;
        s.erase(s.begin());
        for(auto to : e[x])
        {
            if(d[to.first] > d[x] + to.second)
            {
                s.erase(make_pair(d[to.first], to.first));
                d[to.first] = d[x] + to.second;
                s.insert(make_pair(d[to.first], to.first));
            }
        }
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < e[i].size(); ++j)
        {
            if(d[i] + e[i][j].second == d[e[i][j].first])
            {
                v[i].push_back(e[i][j].first);
                vr[e[i][j].first].push_back(i);
            }
        }
}

int dfs1(int x)
{
    if(used[x])
        return dps[x];

    used[x] = 1;

    if(x == S)
    {
        dps[x] = 1;
        return dps[x];
    }

    for(int to : vr[x])
        dps[x] = (dps[x]  + dfs1(to)) % MOD;

    return dps[x];
}

int dfs2(int x)
{
    if(used[x])
        return dpt[x];

    used[x] = 1;

    if(x == T)
    {
        dpt[x] = 1;
        return dpt[x];
    }

    for(int to : v[x])
        dpt[x] = (dpt[x]  + dfs2(to)) % MOD;

    return dpt[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt", "r", stdin);

    cout.precision(9);

    cin >> n >> m;
    cin >> S >> T;
    for(int i = 1; i <= m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        e[x].push_back(make_pair(y, z));
        e[y].push_back(make_pair(x, z));
    }

    dj();

    int ans = dfs1(T);

    ans = (ans * 1ll * ans) % MOD;

    memset(used, 0, sizeof(used));

    dfs2(S);

    for(int i = 1; i <= n; ++i)
    {
        if(d[i] == d[T] - d[i])
        {
            long long x = (dps[i] * 1ll * dpt[i]) % MOD;
            x = (x * 1ll * x) % MOD;
            ans = (ans - x + MOD) % MOD;
        }
        for(int j = 0; j < e[i].size(); ++j)
        {
            if(e[i][j].second + d[i] == d[e[i][j].first])
            {
                int y = e[i][j].first;
                int x = i;
                long long P = d[T] - d[y];

                if(abs(P - d[x]) < e[i][j].second)
                {
                    long long k = (dps[x] * 1ll * dpt[y]) % MOD;
                    k = (k * 1ll * k) % MOD;
                    ans = (ans - k + MOD) % MOD;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
