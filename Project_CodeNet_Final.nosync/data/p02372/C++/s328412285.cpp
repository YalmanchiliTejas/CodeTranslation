#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

using E = tuple<int, int>;
vector<vector<E>> edge;
vector<int> dp1, dp2;

void dfs1(int node, int parent)
{
    dp1[node] = 0;
    for (E e : edge[node]) {
        int v, w;
        tie(v, w) = e;
        if (v != parent) {
            dfs1(v, node);
            dp1[node] = max(dp1[node], dp1[v] + w);
        }
    }
}

void dfs2(int node, int parent, int other)
{
    dp2[node] = max(dp1[node], other);

    int n = edge[node].size();
    vector<int> lmax(n + 1), rmax(n + 1);
    lmax[0] = rmax[n] = 0;
    rep(i, n)
    {
        int v, w;
        tie(v, w) = edge[node][i];
        lmax[i + 1] = rmax[i] = (v == parent ? 0 : dp1[v] + w);
    }

    rep(i, n)
    {
        lmax[i + 1] = max(lmax[i + 1], lmax[i]);
        rmax[n - (i + 1)] = max(rmax[n - (i + 1)], rmax[n - i]);
    }

    rep(i, n)
    {
        int v, w;
        tie(v, w) = edge[node][i];
        if (v != parent) {
            dfs2(v, node, w + max(other, max(lmax[i], rmax[i + 1])));
        }
    }
}

int main()
{
    int n;
    cin >> n;

    edge.resize(n);
    rep(i, n - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back(E(b, c));
        edge[b].push_back(E(a, c));
    }

    dp1.resize(n);
    dfs1(0, 0);

    dp2.resize(n);
    dfs2(0, 0, 0);

    rep(i, n)
    {
        cout << dp2[i] << endl;
    }
    return 0;
}
