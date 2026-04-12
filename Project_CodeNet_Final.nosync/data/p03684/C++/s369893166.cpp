#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, int(n) + 1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)
const int MOD = 1000000007;

template <typename T>
void __dump__(std::ostream &os, const T &first) {
    os << first;
}
template <typename First, typename... Rest>
void __dump__(std::ostream &os, const First &first, const Rest &... rest) {
    os << first << ", ";
    __dump__(os, rest...);
}
#define dump(...)                                         \
    do {                                                  \
        std::ostringstream os;                            \
        os << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; \
        __dump__(os, __VA_ARGS__);                        \
        std::cerr << os.str() << std::endl;               \
    } while (0)

struct uf_tree {
    std::vector<int> parent;
    int __size;
    uf_tree(int size_) : parent(size_, -1), __size(size_) {}
    void unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) std::swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            __size--;
        }
    }
    bool is_same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return __size; }
};

signed main() {
    int n;
    while (cin >> n && n) {
        vector<pair<int, int>> ps(n);
        vector<pair<int, int>> ps2(n);
        rep(i, n) {
            int x, y;
            cin >> x >> y;
            ps[i] = make_pair(x, i);
            ps2[i] = make_pair(y, i);
        }
        sort(all(ps));
        sort(all(ps2));
        vector<tuple<int,int,int>> es;
        rep(i, n - 1) {
            int dx = ps[i + 1].first - ps[i].first;
            int a = ps[i].second;
            int b = ps[i + 1].second;
            es.emplace_back(dx, a, b);
        }
        rep(i, n - 1) {
            int dy = ps2[i + 1].first - ps2[i].first;
            int a = ps2[i].second;
            int b = ps2[i + 1].second;
            es.emplace_back(dy, a, b);
        }
        sort(all(es));

        int ans = 0;
        uf_tree t(n);
        for (auto &e : es) {
            int w, a, b;
            tie(w, a, b) = e;
            // dump(w, a, b);
            if (!t.is_same(a, b)) {
                t.unite(a, b);
                dump(w, a, b);
                ans += w;
            }
        }
        cout << ans << endl;
    }
}
