#include <bits/stdc++.h>
#define maxN 100002
#define inf 1000000001
using namespace std;

//FILE *fin = freopen("d.in", "r", stdin);

int n;
struct Point
{
    int x, y;
    bool operator < (const Point &ot) const
    {
        if (y == ot.y)
            return x < ot.x;
        return y < ot.y;
    }
}v[maxN];

struct Edge
{
    int x, y, c;
    bool operator < (const Edge &ot) const
    {
            return c < ot.c;
    }
}edges[maxN * 2];
vector < Point > X, Y;
int f[maxN], E;

int ans;
int root(int x)
{
    if (!f[x])
        return x;
    return f[x] = root(f[x]);
}
void MST()
{
    sort(edges + 1, edges + E + 1);
    for (int i = 1; i <= E; ++ i)
        {
            int rx = root(edges[i].x), ry = root(edges[i].y);
            if (rx != ry)
            {
                f[rx] = ry;
                ans += edges[i].c;
            }
        }

}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
        {
            scanf("%d %d", &v[i].x, &v[i].y);
            X.push_back({i, v[i].x});
            Y.push_back({i, v[i].y});
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        for (int i = 0; i < n - 1; ++ i)
        {
            edges[++ E] = {X[i].x, X[i + 1].x, X[i + 1].y - X[i].y};
            edges[++ E] = {Y[i].x, Y[i + 1].x, Y[i + 1].y - Y[i].y};
        }
        MST();
    printf("%d\n", ans);
    return 0;
}
