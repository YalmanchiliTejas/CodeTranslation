#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

template <typename T>
struct edge
{
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

//Weighted edge set
template <typename T>
using Edges = vector<edge<T>>;

//Weighted graph
template <typename T>
using WeightedGraph = vector<Edges<T>>;

template <typename T>
T Prim(WeightedGraph<T> &g)
{
    T res = 0;
    vector<bool> used(g.size(), false);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
    que.emplace(0, 0);
    while (que.empty() != true)
    {
        auto p = que.top();
        que.pop();
        if (used[p.second] == true)
            continue;
        used[p.second] = true;
        res += p.first;
        for (auto &e : g[p.second])
        {
            que.emplace(e.cost, e.to);
        }
    }
    return res;
}

int N, a, b, c, d, p1, p2;

int main()
{
    cin >> N;
    vector<pair<pair<int, int>, int>> x, y;
    WeightedGraph<int> G(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &a, &b);
        a--, b--;
        x.emplace_back(make_pair(a, b), i);
        y.emplace_back(make_pair(b, a), i);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for (int i = 0; i + 1 < N; i++)
    {
        a = x[i].first.first, b = x[i].first.second, c = x[i + 1].first.first, d = x[i + 1].first.second, p1 = x[i].second, p2 = x[i + 1].second;
        G[p1].emplace_back(p2, min(abs(a - c), abs(b - d)));
        G[p2].emplace_back(p1, min(abs(a - c), abs(b - d)));

        a = y[i].first.first, b = y[i].first.second, c = y[i + 1].first.first, d = y[i + 1].first.second, p1 = y[i].second, p2 = y[i + 1].second;
        G[p1].emplace_back(p2, min(abs(a - c), abs(b - d)));
        G[p2].emplace_back(p1, min(abs(a - c), abs(b - d)));
    }

    printf("%d\n", Prim(G));
}