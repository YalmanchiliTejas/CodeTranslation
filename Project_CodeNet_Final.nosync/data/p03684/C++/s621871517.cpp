#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

struct Node {
    int x, y, id;
}p[N];
bool cmp1(Node a, Node b) {
    return a.x < b.x;
}
bool cmp2(Node a, Node b) {
    return a.y < b.y;
}
struct Edge {
    int u, v, w;
    bool operator < (const Edge &t) const {
        return w < t.w;
    }
}e[N << 1];
int fa[N];

inline int getFa(int u) {
    return fa[u] == 0 ? u : fa[u] = getFa(fa[u]);
}

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif // purple_bro
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].id = i;
    }

    sort(p + 1, p + 1 + n, cmp1);

    int tot = 0;

    for (int i = 1; i < n; i++)
        e[++tot] = {p[i].id, p[i + 1].id, p[i + 1].x - p[i].x};

    sort(p + 1, p + 1 + n, cmp2);

    for (int i = 1; i < n; i++)
        e[++tot] = {p[i].id, p[i + 1].id, p[i + 1].y - p[i].y};

    sort(e + 1, e + 1 + tot);

    LL ans = 0;
    int cnt = 0;

    for (int i = 1; i <= tot; i++) {
        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;
        int du = getFa(u);
        int dv = getFa(v);
        if (du != dv) {
            fa[du] = dv;
            cnt++;
            ans += w;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
