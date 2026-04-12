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

    void update(int k, const T& x) {
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

    template <typename F>
    int find_subtree(int l, const F& check, T& x, bool type) {
        while (l < size) {
            T nxt = type ? op(node[2 * l + type], x) : op(x, node[2 * l + type]);
            if (check(nxt)) l = 2 * l + type;
            else x = nxt, l = 2 * l + 1 - type;
        }
        return l - size;
    }

    template <typename F>
    int find_first(int l, const F& check) {
        T cur = id;
        int r = 2 * size;
        for (l += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                T nxt = op(cur, node[l]);
                if (check(nxt)) return find_subtree(l, check, cur, false);
                cur = nxt;
                l++;
            }
        }
        return -1;
    }

    template <typename F>
    int find_last(int r, const F& check) {
        T cur = id;
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                r--;
                T nxt = op(node[r], cur);
                if (check(nxt)) return find_subtree(r, check, cur, true);
                cur = nxt;
            }
        }
        return -1;
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
            int j = st.find_first(X - 1, [&](int v) { return v >= V; });
            cout << (j == -1 ? N + 1 : j + 1) << "\n";
        }
    }
}