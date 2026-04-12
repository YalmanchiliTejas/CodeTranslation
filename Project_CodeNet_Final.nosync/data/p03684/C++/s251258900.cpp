#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstdlib>

struct point
{
    int x, y, org;
} p[100001];

int par[100001], rank[100001];

typedef std::pair<int, int> pi;
typedef std::pair<int, std::pair<int, int>> pii;
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> edge;

int parent(int u)
{
    if (u == par[u])
        return u;
    else
        return par[u] = parent(par[u]);
}

void joint(int u, int v)
{
    if (rank[u] > rank[v])
    {
        par[v] = u;
        rank[u] += rank[v];
    }
    else
    {
        par[u] = v;
        rank[v] += rank[u];
    }
}

signed main()
{
    // freopen("a.inp", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int points, k;

    std::cin >> points;
    int x, y;
    for (int i = 0; i < points; ++i)
    {
        par[i] = i;
        p[i].org = i;
        std::cin >> p[i].x >> p[i].y;
    }
    std::sort(p, p + points, [](const point &p1, const point &p2) { return p1.x < p2.x; });
    for (int i = 0; i < points - 1; ++i)
        edge.push(pii(std::min(p[i + 1].x - p[i].x, abs(p[i + 1].y - p[i].y)), pi(p[i].org, p[i + 1].org)));
    std::sort(p, p + points, [](const point &p1, const point &p2) { return p1.y < p2.y; });
    for (int i = 0; i < points - 1; ++i)
        edge.push(pii(std::min(p[i + 1].y - p[i].y, abs(p[i + 1].x - p[i].x)), pi(p[i].org, p[i + 1].org)));
    unsigned s = 0;
    int tmp = 1;
    while (!edge.empty())
    {
        if (tmp == points)
            break;
        pii temp = edge.top();
        edge.pop();
        int cost = temp.first;
        int p_u = parent(temp.second.first);
        int p_v = parent(temp.second.second);
        if (p_u != p_v)
        {
            ++tmp;
            s += cost;
            joint(p_u, p_v);
        }
    }
    std::cout << s;
    return 0;
}