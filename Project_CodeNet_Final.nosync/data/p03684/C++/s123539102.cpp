#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    ll n;
    cin >> n;
    using P = pair<ll, ll>;
    vector<P> x(n);
    vector<P> y(n);
    for(int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        x[i] = P(a, i);
        y[i] = P(b, i);
    }
    vector<edge> es;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for(int i = 0; i < n-1; i++)
    {
        ll cost = x[i+1].first - x[i].first;
        edge e = {x[i+1].second, x[i].second, cost};
        es.push_back(e);
    }
    for(int i = 0; i < n-1; i++)
    {
        ll cost = y[i+1].first - y[i].first;
        edge e = {y[i+1].second, y[i].second, cost};
        es.push_back(e);
    }

    // kruscal start
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
