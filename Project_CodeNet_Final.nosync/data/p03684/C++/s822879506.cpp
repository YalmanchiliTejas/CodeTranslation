#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100010

struct point {int id, x, y;};
struct edge {int u, v, w;};

int n;
point p[MAX_N];
edge edgeset[2 * MAX_N];

int pa[MAX_N];
int rnk[MAX_N];

void init(void)
{
    memset(pa, 0, sizeof(pa));
    memset(rnk, 0, sizeof(rnk));
    for (int i = 0; i < n; i++) {
        pa[i] = i;
        rnk[i] = 0;
    }
}

int find(int x)
{
    if (pa[x] == x) return x;
    else return pa[x] = find(pa[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) pa[x] = y;
    else {
        pa[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int x, int y)
{
    return (find(x) == find(y));
}

int abs(int a)
{
    return a >= 0? a: -a;
}

bool cmp_x(point a, point b)
{
    return a.x < b.x;
}

bool cmp_y(point a, point b)
{
    return a.y < b.y;
}

bool cmp_edge(edge a, edge b)
{
    return a.w < b.w;
}

int mst(void)
{
    init();
    int res = 0;
    for (int i = 0; i < 2 * (n - 1); i++) {
        edge e = edgeset[i];
        if (!same(e.u, e.v)) {
            unite(e.u ,e.v);
            res += e.w;
        }
    }
    return res;
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].id = i;
    }
    sort(p, p + n, cmp_x);
    for (int i = 0; i < n - 1; i++) {
        edgeset[i].u = p[i].id;
        edgeset[i].v = p[i + 1].id;
        edgeset[i].w = abs(p[i + 1].x - p[i].x);
    }
    sort(p, p + n, cmp_y);
    for (int i = 0; i < n - 1; i++) {
        edgeset[i + n - 1].u = p[i].id;
        edgeset[i + n - 1].v = p[i + 1].id;
        edgeset[i + n - 1].w = abs(p[i + 1].y - p[i].y);
    }
    sort(edgeset, edgeset + 2 * (n - 1), cmp_edge);
    printf("%d\n", mst());
    return 0;
}
