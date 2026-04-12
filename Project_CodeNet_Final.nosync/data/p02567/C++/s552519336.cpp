#include <iostream>
#include <vector>
#include <atcoder/segtree>

namespace ac = atcoder;
constexpr int INF = 1 << 30;

int e() { return -INF; }
int max(int a, int b) { return std::max(a, b); }

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    ac::segtree<int, max, e> seg(xs);

    while (q--) {
        int t;
        std::cin >> t;

        switch (t) {
            case 1: {
                int i, x;
                std::cin >> i >> x;
                seg.set(--i, x);
                break;
            }
            case 2: {
                int l, r;
                std::cin >> l >> r;
                std::cout << seg.prod(--l, r) << "\n";
                break;
            }
            case 3: {
                int l, a;
                std::cin >> l >> a;

                auto lt = [&](int x) { return x < a; };
                int r = seg.max_right(--l, lt);
                std::cout << r + 1 << "\n";
                break;
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
