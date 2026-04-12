#include <bits/stdc++.h>
using namespace std;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(12), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
using Int = long long;
struct SegTree {
    int N;
    vector<int> A;
    SegTree(int n) {
        N = 1; while (N < n) N *= 2;
        A.resize(2 * N);
    }
    void set(int idx, int val) {
        idx += N;
        A[idx] = val;
        idx >>= 1;
        while (idx > 0) {
            A[idx] = max(A[2*idx+0], A[2*idx+1]);
            idx >>= 1;
        }
    }
    int maximum(int L, int R) {
        L += N, R += N;
        int ans = INT_MIN;
        while (L < R) {
            if (L & 1) ans = max(ans, A[L++]);
            if (R & 1) ans = max(ans, A[--R]);
            L >>= 1, R >>= 1;
        }
        return ans;
    }
    int find_ge_0(int L, int val, int node, int nodeL, int nodeR) {
        if (nodeR <= L || A[node] < val) {
            return -1;
        }
        if (nodeR - nodeL == 1) {
            return node - N;
        }
        int idx = 0;
        if ((idx = find_ge_0(L, val, 2*node+0, nodeL, (nodeL + nodeR) / 2)) >= 0 ||
            (idx = find_ge_0(L, val, 2*node+1, (nodeL + nodeR) / 2, nodeR)) >= 0) {
            return idx;
        }
        return -1;
    }
    int find_ge(int L, int val) { // min idx s.t. idx >= L && st[idx] >= val
        return find_ge_0(L, val, 1, 0, N);
    }
};
int main() {
    int N, Q; cin >> N >> Q;
    SegTree st(N);
    for (int i = 0; i < N; i++) {
        int a; cin >> a; st.set(i, a);
    }
    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int x, v; cin >> x >> v; x--;
            st.set(x, v);
        } else if (t == 2) {
            int l, r; cin >> l >> r; l--, r--;
            cout << st.maximum(l, r + 1) << '\n';
        } else {
            int x, v; cin >> x >> v; x--;
            int idx = st.find_ge(x, v);
            cout << (idx < 0 ? N + 1 : idx + 1) << '\n';
        }
    }
    return 0;
}
