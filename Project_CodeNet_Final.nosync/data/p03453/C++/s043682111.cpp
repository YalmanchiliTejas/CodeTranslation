#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int s, t;
    scanf("%d%d", &s, &t);
    s--, t--;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    constexpr int kMod = 1'000'000'000 + 7;

    auto Dijkstra = [&](int r) {
        constexpr int64_t kInf = 1'000'000'000'000'000'000;
        vector<pair<int64_t, int>> sp(n, make_pair(kInf, 0));
        vector<int> used(n);
        priority_queue<pair<int64_t, int>> pq;
        sp[r] = make_pair(0, 1);
        pq.emplace(0, r);
        while (!pq.empty()) {
            int x = pq.top().second;
            pq.pop();
            if (used[x]++) continue;
            for (auto e : g[x]) {
                if (sp[e.first].first > sp[x].first + e.second) {
                    sp[e.first].first = sp[x].first + e.second;
                    sp[e.first].second = sp[x].second;
                    pq.emplace(-sp[e.first].first, e.first);
                } else if (sp[e.first].first == sp[x].first + e.second) {
                    sp[e.first].second += sp[x].second;
                    if (sp[e.first].second >= kMod) sp[e.first].second -= kMod;
                }
            }
        }
        return sp;
    };

    auto ds = Dijkstra(s);
    auto dt = Dijkstra(t);
    const int64_t dist = ds[t].first;
    assert(dt[s].first == dist);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (auto e : g[i]) {
            if (ds[i].first + e.second + dt[e.first].first == dist && ds[i].first * 2 < dist && ds[e.first].first * 2 > dist) {
                int ways = 1LL * ds[i].second * dt[e.first].second % kMod;
                ways = 1LL * ways * ways % kMod;
                (ans += ways) >= kMod ? ans -= kMod : 0;
            }
        }
        if (ds[i].first == dt[i].first && ds[i].first * 2 == dist) {
            int ways = 1LL * ds[i].second * dt[i].second % kMod;
            ways = 1LL * ways * ways % kMod;
            (ans += ways) >= kMod ? ans -= kMod : 0;
        }
    }
    assert(ds[t].second == dt[s].second);
    ans = (1LL * ds[t].second * ds[t].second % kMod + kMod - ans) % kMod;
    printf("%d\n", ans);
    return 0;
}
