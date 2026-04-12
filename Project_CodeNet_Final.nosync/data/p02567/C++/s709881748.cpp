#include <atcoder/segtree>
#include <iostream>
#include <vector>

int op(int a, int b)
{
    return std::max(a, b);
}

int e()
{
    return -1;
}

int V;
bool f(int i)
{
    return i < V;
}

int main()
{
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for (auto &a : A) {
        std::cin >> a;
    }

    atcoder::segtree<int, op, e> seg(A);

    for (int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if (T == 1) {
            int X, V;
            std::cin >> X >> V;

            seg.set(X - 1, V);

        } else if (T == 2) {
            int l, r;
            std::cin >> l >> r;

            std::cout << seg.prod(l - 1, r) << '\n';

        } else {
            int X;
            std::cin >> X >> V;

            std::cout << seg.max_right<f>(X - 1) + 1 << '\n';
        }
    }
}