#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
struct UnionFind
{
    vector<ll> par;
    vector<ll> rank;
    vector<ll> sz;
    UnionFind(ll n) : par(n), rank(n), sz(n)
    {
        for(ll i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 0;
            sz[i] = 1;
        }
    }
    ll root(ll x)
    {
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }
    void unite(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(rank[x] < rank[y])
        {
            par[x] = y;
            sz[y] += sz[x];
        }
        else
        {
            par[y] = x;
            sz[x] += sz[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }
    ll size(ll x)
    {
        x = root(x);
        return sz[x];
    }
};
struct edge {ll u, v, cost;};
bool comp(const edge& e1, const edge& e2)
{
    return e1.cost < e2.cost;
}
int main()
{
    int n;
    cin >> n;
    vector<P> px(n);
    vector<P> py(n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        px[i] = P(x, i);
        py[i] = P(y, i);
    }
    sort(px.begin(), px.end());
    sort(py.begin(), py.end());
    // kruscal start
    vector<edge> es;

    // set es
    for(int i = 1; i < n; i++)
    {
       edge e;
       e.cost = px[i].first - px[i-1].first;
       e.u = px[i].second;
       e.v = px[i-1].second;
       es.push_back(e);
    }
    for(int i = 1; i < n; i++)
    {
       edge e;
       e.cost = py[i].first - py[i-1].first;
       e.u = py[i].second;
       e.v = py[i-1].second;
       es.push_back(e);
    }

    ll V = n;
    UnionFind tree(V);
    ll E = es.size();
    sort(es.begin(), es.end(), comp);
    ll res = 0;
    for(int i = 0; i < E; i++)
    {
        edge e = es[i];
        if(!tree.same(e.u, e.v))
        {
            tree.unite(e.u, e.v);
            res += e.cost;
        }
    }
    cout << res << endl;
    // kruscal end
}
