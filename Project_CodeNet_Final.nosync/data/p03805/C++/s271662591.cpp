#include <cstdio>
#include <algorithm>
static const int MAXN = 8;

int n, m;
bool g[MAXN][MAXN] = {{ false }};
int p[MAXN];

inline bool check()
{
    if (p[0] != 0) return false;
    for (int i = 1; i < n; ++i) if (!g[p[i - 1]][p[i]]) return false;
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        g[u][v] = g[v][u] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) p[i] = i;
    do if (check()) ++ans; while (std::next_permutation(p, p + n));

    printf("%d\n", ans);
    return 0;
}
