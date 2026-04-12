#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>
#include <vector>
#include <functional>

using namespace std;
const int maxn = 1e5 + 6;
using ll = long long;
array<int, maxn> fa;
int n, m;
using pii = pair<int, int>;
array<pii, maxn> sx, sy;

int find_root(int x) { return x == fa[x] ? fa[x] : fa[x] = find_root(fa[x]); }

struct Node {
    int u, v, w;

    Node() {}

    Node(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Node &v) const {
        return w < v.w;
    }
};

vector<Node> edge;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    iota(fa.begin() + 1, fa.begin() + 1 + n, 1);
    for (int i = 1; i <= n; ++i) {
        cin >> sx[i].first >> sy[i].first;
        sx[i].second = sy[i].second = i;
    }
    auto cmp = [&](pii a, pii b) -> bool { return a.first < b.first; };
    sort(sx.begin() + 1, sx.begin() + 1 + n, cmp);
    sort(sy.begin() + 1, sy.begin() + 1 + n, cmp);
    for (int i = 1; i < n; ++i) {
        edge.emplace_back(sx[i].second, sx[i + 1].second, sx[i + 1].first - sx[i].first);
        edge.emplace_back(sy[i].second, sy[i + 1].second, sy[i + 1].first - sy[i].first);
    }
    sort(edge.begin(), edge.end());
    ll ans = 0;
    auto size = static_cast<int>(edge.size());
    for (int i = 0; i < size; ++i) {
        if (find_root(edge[i].u) != find_root(edge[i].v)) {
            ans += edge[i].w;
            fa[find_root(edge[i].u)] = find_root(edge[i].v);
        }
    }
    cout << ans << endl;
}