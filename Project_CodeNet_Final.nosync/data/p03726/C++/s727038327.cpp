#include <cstdio>
#include <vector>

#define MAXN 100000

bool partz, e[MAXN + 1], viz[MAXN + 1];
std::vector < int > g[MAXN + 1];

void dfs(int x) {
    viz[x] = 1;
    int cnt = 0;
    for (auto &y : g[x]) {
        if (viz[y] == 0) {
            dfs(y);
            cnt += 1 - e[y];
        }
    }
    if (cnt == 1)
        e[x] = 1;
    else if (cnt > 1)
        partz = 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    partz |= 1 - e[1];

    if (partz)
        printf("First\n");
    else
        printf("Second\n");

    return 0;
}
