#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int fa[maxn];
struct Node {
    ll x, y, id;
} st[maxn];

struct Edge {
    ll cost, p1, p2;
} edge[maxn * 2];

int cmp1(Node a, Node b)
{
    return a.x < b.x;
}
int cmp2(Node a, Node b)
{
    return a.y < b.y;
}
int cmp3(Edge a, Edge b)
{
    return a.cost < b.cost;
}
int find(int u)
{
    if (fa[u] == u)
        return fa[u];
    return fa[u] = find(fa[u]);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &st[i].x, &st[i].y);
        st[i].id = i;
        fa[i] = i;
    }
    sort(st + 1, st + 1 + n, cmp1);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        edge[++cnt].p1 = st[i - 1].id;
        edge[cnt].p2 = st[i].id;
        edge[cnt].cost = st[i].x - st[i - 1].x;
    }
    sort(st + 1, st + 1 + n, cmp2);
    for (int i = 2; i <= n; i++) {
        edge[++cnt].p1 = st[i - 1].id;
        edge[cnt].p2 = st[i].id;
        edge[cnt].cost = st[i].y - st[i - 1].y;
    }
    sort(edge + 1, edge + 1 + cnt, cmp3);
    ll ans = 0;
    int num = 0;
    for (int i = 1; i <= cnt; i++) {
        int fa_p1 = find(edge[i].p1);
        int fa_p2 = find(edge[i].p2);
        if (fa_p1 == fa_p2)
            continue;
        else {
            fa[fa_p1] = fa_p2;
            num++;
            ans += (edge[i].cost);
        }
        if (num == n - 1)
            break;
    }
    printf("%lld\n", ans);
    return 0;
}