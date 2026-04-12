#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

int dfs(
    const std::vector<std::vector<size_t>> &g, std::set<size_t> &s,
    size_t r, size_t p
) {
    if (s.size() == g.size()-1) return 1;
    if (s.count(r)) return 0;

    int res=0;
    s.insert(r);
    for (size_t c: g[r])
        if (c != p && !s.count(c))
            res += dfs(g, s, c, r);

    s.erase(r);
    return res;
}

int main() {
    size_t N;
    int M;
    scanf("%zu %d", &N, &M);

    std::vector<std::vector<size_t>> g(N);
    for (int i=0; i<M; ++i) {
        size_t a, b;
        scanf("%d %d", &a, &b);

        --a, --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    std::set<size_t> s;
    printf("%d\n", dfs(g, s, 0, -1));
    return 0;
}
