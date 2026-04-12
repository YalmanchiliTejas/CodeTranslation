#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

struct Edge
{
    int to, cost, memo;
};

int n;
using Graph = vector<vector<Edge>>;
Graph g(10000);

int dfs(int cur, int pre)
{
    int ret = 0;
    for (auto &e : g[cur])
    {
        if (e.to == pre)
            continue;
        if(e.memo == -1){
            e.memo = dfs(e.to, cur);
        }
        ret = max(ret, e.memo + e.cost);
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int s, t, w;
        cin >> s >> t >> w;
        g[s].push_back(Edge{t, w, -1});
        g[t].push_back(Edge{s, w, -1});
    }
    for (int i = 0; i < n; i++)
    {
        cout << dfs(i, -1) << endl;
    }
}

