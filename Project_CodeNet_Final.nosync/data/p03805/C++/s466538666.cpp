#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int dfs(const vector<vector<size_t>> &g, size_t v, set<size_t> s) {
    s.insert(v);
    if (s.size() == g.size())
        return 1;

    int res=0;
    for (size_t e: g[v]) {
        if (s.count(e)) continue;
        res += dfs(g, e, s);
    }

    return res;
}

int main() {
    size_t N, M;
    scanf("%zu %zu", &N, &M);

    vector<vector<size_t>> g(N);
    for (size_t i=0; i<M; ++i) {
        size_t a, b;
        scanf("%zu %zu", &a, &b);
        --a, --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    printf("%d\n", dfs(g, 0, {}));
    return 0;
}
