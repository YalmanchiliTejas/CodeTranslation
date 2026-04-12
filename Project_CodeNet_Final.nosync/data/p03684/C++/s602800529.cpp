#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct town
{
    int ind, val;
} x[100005], y[100005];
struct edge
{
    int u, v, w;
} e[200005];
int i, n, dsu[1000005];
long long ans = 0;

inline bool operator < (const town &a, const town &b)
{
    return a.val < b.val;
}

inline bool operator < (const edge &a, const edge &b)
{
    return a.w < b.w;
}

int trace(int i)
{
    if (dsu[i] < 0)
        return i;
    dsu[i] = trace(dsu[i]);
    return dsu[i];
}

bool unity(int a, int b)
{
    int x = trace(a), y = trace(b);
    if (x == y)
        return 0;
    if (dsu[x] > dsu[y])
        swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
    return 1;
}

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        dsu[i] = -1;
        x[i].ind = y[i].ind = i;
        scanf("%d%d", &x[i].val, &y[i].val);
    }
    sort(x + 1, x + n + 1); sort(y + 1, y + n + 1);
    for (i = 1; i < n; i++)
    {
        e[2 * i - 1].u = x[i].ind; e[2 * i - 1].v = x[i + 1].ind; e[2 * i - 1].w = x[i + 1].val - x[i].val;
        e[2 * i].u = y[i].ind; e[2 * i].v = y[i + 1].ind; e[2 * i].w = y[i + 1].val - y[i].val;
    }
    sort(e + 1, e + 2 * n - 1);
    for (i = 1; i <= 2 * n - 2; i++)
        ans += (long long)e[i].w * (unity(e[i].u, e[i].v));
    printf("%lld", ans);
}
