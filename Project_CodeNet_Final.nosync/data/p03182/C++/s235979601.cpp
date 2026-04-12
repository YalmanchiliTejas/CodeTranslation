#include <bits/stdc++.h>
using namespace std;
using Int = long long;
struct LazySegTree {
    int N;
    vector<Int> A, B;
    LazySegTree(int n) {
        N = 1;
        while (N < n) N *= 2;
        A.resize(2 * N);
        B.resize(N);
    }
    void addrange(int L, int R, Int value) {
        L += N, R += N;
        int L0 = L, R0 = R;
        while (L < R) {
            if (R & 1) apply(--R, value);
            if (L & 1) apply(L++, value);
            L /= 2, R /= 2;
        }
        build(L0), build(R0 - 1);
    }
    Int maxrange(int L, int R) {
        Int ans = LLONG_MIN;
        L += N, R += N;
        push(L), push(R - 1);
        while (L < R) {
            if (R & 1) ans = max(ans, A[--R]);
            if (L & 1) ans = max(ans, A[L++]);
            L /= 2, R /= 2;
        }
        return ans;
    }
    void apply(int X, Int value) {
        A[X] += value;
        if (X < N) B[X] += value;
    }
    void build(int X) {
        X /= 2;
        while (X > 0) {
            A[X] = max(A[2 * X + 0], A[2 * X + 1]) + B[X];
            X /= 2;
        }
    }
    void push(int X) {
        for (int s = 32 - __builtin_clz(N); s > 0; s--) {
            int i = X >> s;
            apply(2 * i + 0, B[i]);
            apply(2 * i + 1, B[i]);
            B[i] = 0;
        }
    }
};
int main() {
    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> A(N + 2);
    for (int i = 0; i < M; i++) {
        int l, r, a; cin >> l >> r >> a;
        A[l].emplace_back(l, a);
        A[r + 1].emplace_back(l, -a);
    }
    LazySegTree dp(N + 2);
    for (int i = 1; i <= N + 1; i++) {
        for (auto &p : A[i]) {
            dp.addrange(0, p.first, p.second);
        }
        dp.addrange(i, i + 1, dp.maxrange(0, i));
    }
    cout << dp.maxrange(0, N + 1) << '\n';
    return 0;
}
