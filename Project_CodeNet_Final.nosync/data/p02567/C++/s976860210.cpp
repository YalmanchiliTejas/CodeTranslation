#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T, T (*op)(T, T), T id>
struct SegmentTree {
    int size;
    vector<T> node;

    SegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        node.resize(2 * size, id);
    }

    T operator[](int k) {
        return node[k + size];
    }

    void build(const vector<T>& v) {
        for (int k = 0; k < v.size(); k++) node[k + size] = v[k];
        for (int k = size - 1; k > 0; k--) node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    void update(int k, T x) {
        k += size;
        node[k] = x;
        while (k >>= 1) {
            node[k] = op(node[2 * k], node[2 * k + 1]);
        }
    }

    T query(int l, int r) {
        T L = id, R = id;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = op(L, node[l++]);
            if (r & 1) R = op(node[--r], R);
        }
        return op(L, R);
    }
};

int op(int a, int b) {
    return max(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    SegmentTree<int, op, 0> st(N);
    st.build(A);
    for (int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        if (T == 1) {
            int X, V;
            cin >> X >> V;
            st.update(X - 1, V);
        } else if (T == 2) {
            int L, R;
            cin >> L >> R;
            cout << st.query(L - 1, R) << "\n";
        } else {
            int X, V;
            cin >> X >> V;
            int lb = X - 1, ub = N + 1;
            while (ub - lb > 1) {
                int m = (lb + ub) / 2;
                if (st.query(X - 1, m) >= V) ub = m;
                else lb = m;
            }
            cout << ub << "\n";
        }
    }
}