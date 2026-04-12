#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <bits/stdc++.h>
using namespace std;

template <typename T, T (*op)(T, T), T id>
struct SegmentTree {
public:
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
        while (k >>= 1) node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    T query(int l, int r) {
        T L = id, R = id;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = op(L, node[l++]);
            if (r & 1) R = op(node[--r], R);
        }
        return op(L, R);
    }

    int find_first(int l, const function<bool(T)>& cond) {
        T L = id;
        int r = 2 * size;
        for (l += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                T nxt = op(L, node[l]);
                if (cond(nxt)) return find_subtree(l, cond, L, 0);
                L = nxt;
                l++;
            }
        }
        return -1;
    }

    int find_last(int r, const function<bool(T)>& cond) {
        T R = id;
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                r--;
                T nxt = op(node[r], R);
                if (cond(nxt)) return find_subtree(r, cond, R, 1);
                R = nxt;
            }
        }
        return -1;
    }

private:
    int size;
    vector<T> node;

    int find_subtree(int l, const function<bool(T)>& check, T& x, int type) {
        while (l < size) {
            T nxt = type ? op(node[2 * l + type], x) : op(x, node[2 * l + type]);
            if (check(nxt)) l = 2 * l + type;
            else x = nxt, l = 2 * l + 1 - type;
        }
        return l - size;
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