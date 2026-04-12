#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T, T (*op)(T, T), T id>
struct SegmentTree {
    int size;
    vector<T> node;

    SegmentTree(int n) : SegmentTree(vector<T>(n, id)) {}
    SegmentTree(const vector<T>& v) {
        size = 1;
        while (size < v.size()) size <<= 1;
        node.resize(2 * size, id);
        for (int i = 0; i < v.size(); i++) node[i + size] = v[i];
        for (int i = size - 1; i > 0; i--) node[i] = op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) const {
        return node[k + size];
    }

    void update(int k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    T query(int l, int r) {
        T vl = id, vr = id;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = op(vl, node[l++]);
            if (r & 1) vr = op(node[--r], vr);
        }
        return op(vl, vr);
    }

    int find_first(int l, const function<bool(T)>& cond) {
        T vl = id;
        int r = 2 * size;
        for (l += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                T nxt = op(vl, node[l]);
                if (cond(nxt)) {
                    while (l < size) {
                        nxt = op(vl, node[2 * l]);
                        if (cond(nxt)) l = 2 * l;
                        else vl = nxt, l = 2 * l + 1;
                    }
                    return l - size;
                }
                vl = nxt;
                l++;
            }
        }
        return -1;
    }

    int find_last(int r, const function<bool(T)>& cond) {
        T vr = id;
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                r--;
                T nxt = op(node[r], vr);
                if (cond(nxt)) {
                    while (r < size) {
                        nxt = op(node[2 * r + 1], vr);
                        if (cond(nxt)) r = 2 * r + 1;
                        else vr = nxt, r = 2 * r;
                    }
                    return r - size;
                }
                vr = nxt;
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
    SegmentTree<int, op, 0> st(A);
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