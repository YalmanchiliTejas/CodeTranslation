#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, fa[maxn];
long long ans;
struct node { int x, y, id; };
node p[maxn];
struct edge { int u, v, w; };
vector<edge> E;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y), p[i].id = fa[i] = i;
    }
    sort(p + 1, p + n + 1, [&](node x, node y) { return x.x < y.x; });
    for (int i = 1; i < n; i++) {
        E.push_back((edge){p[i].id, p[i + 1].id, p[i + 1].x - p[i].x});
    }
    sort(p + 1, p + n + 1, [&](node x, node y) { return x.y < y.y; });
    for (int i = 1; i < n; i++) {
        E.push_back((edge){p[i].id, p[i + 1].id, p[i + 1].y - p[i].y});
    }
    sort(E.begin(), E.end(), [&](edge x, edge y) { return x.w < y.w; });
    for (auto e : E) {
        if (find(e.u) == find(e.v)) continue;
        fa[find(e.u)] = find(e.v), ans += e.w; 
    }
    printf("%lld\n", ans);
    return 0;
}