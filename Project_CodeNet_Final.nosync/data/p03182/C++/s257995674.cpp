#include <bits/stdc++.h>
using namespace std;

template<class Monoid, class OperatorMonoid, class FunctionM, class FunctionMO, class FunctionO>
struct LazySegmentTree {
    int N; vector<Monoid> segment; vector<OperatorMonoid> lazy;
    const FunctionM FuncM; const FunctionMO FuncMO; const FunctionO FuncO;
    const Monoid idM; const OperatorMonoid idOM;

    LazySegmentTree(int n, const FunctionM FuncM, const FunctionMO FuncMO, const FunctionO FuncO,
        const Monoid idM, const OperatorMonoid idOM)
    : FuncM(FuncM), FuncMO(FuncMO), FuncO(FuncO), idM(idM), idOM(idOM) {
        N = 1;
        while (N < n) N <<= 1;
        segment.assign(2 * N, idM); lazy.assign(2 * N, idOM);
    }

    LazySegmentTree(int n, const FunctionM FuncM, const FunctionMO FuncMO, const FunctionO FuncO,
        const Monoid idM, const OperatorMonoid idOM, const Monoid initVal)
    : FuncM(FuncM), FuncMO(FuncMO), FuncO(FuncO), idM(idM), idOM(idOM) {
        N = 1;
        while (N < n) N <<= 1;
        segment.assign(2 * N, initVal); lazy.assign(2 * N, idOM);
    }

    void set(int num, Monoid x) {
        segment[N + num] = x;
    }
    void build() {
        for (int k = N - 1; k > 0; k--) {
            segment[k] = FuncM(segment[2*k], segment[2*k+1]);
        }
    }

    inline void propagate(int k, int len){
        if (lazy[k] != idOM) {
            if (k < N) {
                lazy[2*k] = FuncO(lazy[2*k], lazy[k]);
                lazy[2*k+1] = FuncO(lazy[2*k+1], lazy[k]);
            }
            segment[k] = FuncMO(segment[k], lazy[k], len);
            lazy[k] = idOM;
        }
    }

    // update:[a, b)
    Monoid update(int a, int b, const OperatorMonoid x) {
        return update(a, b, x, 1, 0, N);
    }
    Monoid update(int a, int b, const OperatorMonoid x, int k, int l, int r){
        propagate(k, r-l);
        if (b <= l || r <= a) {
            return segment[k];
        } else if (a <= l && r <= b) {
            lazy[k] = FuncO(lazy[k], x);
            propagate(k, r-l);
            return segment[k];
        } else {
            int m = (l + r) / 2;
            return segment[k] = FuncM(update(a, b, x, 2*k, l, m), update(a, b, x, 2*k+1, m, r));
        }
    }

    // query:[a, b)
    Monoid query(int a, int b) {
        return query(a, b, 1, 0, N);
    }
    Monoid query(int a, int b, int k, int l, int r) {
        propagate(k, r-l);
        if (b <= l || r <= a) {
            return idM;
        } else if (a <= l && r <= b) {
            return segment[k];
        } else {
            int m = (l + r) / 2;
            return FuncM(query(a, b, 2*k, l, m), query(a, b, 2*k+1, m, r));
        }
    }

    // 0-indexed numbering;
    inline Monoid operator[](const int &k) {
        return query(k, k + 1);
    }
};

auto F = [&](long long a, long long b) {return max(a, b);};
auto G = [&](long long a, long long b, int len) {return a + b;};
auto H = [&](long long a, long long b) {return a + b;};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<array<int, 3>> v;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        v.push_back({b, a, c});
    }
    v.push_back({n, 0, 0});
    sort(v.begin(), v.end());
    long long inf = 1e16;
    LazySegmentTree<long long, long long, decltype(F), decltype(G), decltype(H)> lst(n+1, F, G, H, -inf, 0);
    lst.update(0, 1, inf);
    lst.build();
    int curr = 1;
    for (auto &iter: v) {
        while (curr <= iter[0]) {
            auto x = lst.query(0, curr);
            lst.update(curr, curr+1, inf+x);
            curr++;
        }
        lst.update(iter[1], iter[0]+1, iter[2]);
    }
    
    long long ans = lst.query(0, n+1);
    cout << ans << "\n";
    return 0;
}