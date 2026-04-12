#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plpll;
typedef pair<pll, pll> llll;

int N, M;
vector<pll> G[4010];
vector<pll> T[4010];
vector<pll> cost;
vector<plpll> E;
bool is_tree[400010];
int par[4010];
ll sum;
int current_root;
ll max_cost[4010][4010];

void init(int N)
{
    for(int i = 0; i < N; i++)par[i] = i;
    return;
}

int root(int x)
{
    if(par[x] == x)return x;
    return par[x] = root(par[x]);
}

void unite(int x, int y)
{
    x = root(x);
    y = root(y);

    if(x == y)return;

    par[x] = y;
    return;
}

bool same(int x, int y)
{
    return root(x) == root(y);
}

void DFS(int v, int p = -1, ll d = 0)
{
    max_cost[current_root][v] = d;
    for(int i = 0; i < T[v].size(); i++)
    {
        int next = T[v][i].fi, id = T[v][i].se;
        ll cost = E[id].fi;
        if(p == next || !is_tree[id])continue;
        DFS(next, v, max(d, cost));
    }
    return;
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        cost.push_back(mk(c, i));
        E.push_back(mk(c, mk(a, b)));
        G[a].push_back(mk(b, i));
        G[b].push_back(mk(a, i));
    }

    init(N);
    sort(cost.begin(), cost.end());
    for(int i = 0; i < M; i++)
    {
        int now = cost[i].se;
        int a = E[now].se.fi, b = E[now].se.se;
        if(!same(a, b))
        {
            sum += cost[i].fi;
            T[a].push_back(mk(b, now));
            T[b].push_back(mk(a, now));
            is_tree[now] = true;
            unite(a, b);
        }
    }

    for(int i = 1; i <= N; i++)
    {
        current_root = i;
        DFS(i);
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << sum - max_cost[a][b] << endl;
    }
}
