#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

struct UnionFind
{
    int n;
    vector<int> parent;
    vector<int> rank;
    UnionFind(int _n) :n(_n)
    {
        parent.assign(n, -1);
        rank.assign(n, 1);
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        else
            return parent[i] = find(parent[i]);
    }

    void unite(int i, int j)
    {
        i = find(i);
        j = find(j);

        if (i == j) return;

        if (rank[i] == rank[j])
        {
            parent[j] = i;
            ++rank[i];
        }
        else
        {
            if (rank[i] < rank[j]) swap(i, j);
            parent[j] = i;
        }
    }

    bool is_same(int i, int j)
    {
        return find(i) == find(j);
    }
};


int main()
{
    int n;
    cin >> n;
    vector<pii> x, y;
    rep(i, 0, n) 
    {
        int xx, yy;
        cin >> xx >> yy;
        x.emplace_back(xx, i);
        y.emplace_back(yy, i);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    vector<tiii> edges;
    rep(i, 0, n - 1)
    {
        int cost;
        cost = abs(x[i].first - x[i + 1].first);
        edges.push_back(make_tuple(cost, x[i].second, x[i + 1].second));

        cost = abs(y[i].first - y[i + 1].first);
        edges.push_back(make_tuple(cost, y[i].second, y[i + 1].second));
    }

    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    ll ans = 0;
    for (auto edge: edges)
    {
        int cost, i, j;
        tie(cost, i, j) = edge;

        if (uf.is_same(i, j)) continue;

        ans += (ll) cost;
        uf.unite(i, j);
    }

    cout << ans << endl;

    return 0;
}