#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
struct SegmentTree {
    int N;
    vector<Int> A;
    SegmentTree(int n, Int init) {
        N = 1;
        while (N < n) N *= 2;
        A.resize(2 * N, init);
    }
    void set(int idx, Int val) {
        idx += N;
        A[idx] = val;
        idx >>= 1;
        while (idx > 0) {
            A[idx] = max(A[2*idx+0], A[2*idx+1]);
            idx >>= 1;
        }
    }
    Int get(int idx) {
        return A[idx + N];
    }
    void chmax(int idx, Int val) {
        if (get(idx) < val) set(idx, val);
    }
    Int maxrange(int L, int R) {
        L += N, R += N;
        Int ans = -1e18;
        while (L < R) {
            if (L & 1) ans = max(ans, A[L++]);
            if (R & 1) ans = max(ans, A[--R]);
            L >>= 1, R >>= 1;
        }
        return ans;
    }
};
int main() {
    int N; cin >> N;
    vector<int> A(3 * N); for (auto &a : A) cin >> a, a--;
    vector<SegmentTree> st(N, SegmentTree(N, -10000));
    int total = 0;
    st[A[0]].set(A[1], 0);
    st[A[1]].set(A[0], 0);
    vector<int> B(3), two_j(N), j_max(N), jj(3);
    for (int i = 2; i + 2 < 3 * N; i += 3) {
        for (int j = 0; j < 3; j++) B[j] = A[i + j];
        if (B[0] == B[1] && B[1] == B[2]) {
            total++;
        } else if (B[0] == B[1] || B[1] == B[2] || B[2] == B[0]) {
            int two = 0, one = 0;
            if (B[0] == B[1]) two = B[0], one = B[2];
            if (B[1] == B[2]) two = B[1], one = B[0];
            if (B[2] == B[0]) two = B[2], one = B[1];
            for (int j = 0; j < N; j++) {
                two_j[j] = st[two].get(j);
                j_max[j] = st[j].maxrange(0, N);
            }
            st[two].chmax(two, st[one].get(one) + 1);
            for (int j = 0; j < N; j++) {
                st[one].chmax(j, two_j[j] + 1);
                st[j].chmax(one, two_j[j] + 1);
            }
            for (int j = 0; j < N; j++) {
                st[j].chmax(two, j_max[j]);
                st[two].chmax(j, j_max[j]);
                st[j].chmax(one, j_max[j]);
                st[one].chmax(j, j_max[j]);
            }
            int tot = 0;
            for (int j = 0; j < N; j++) tot = max(tot, j_max[j]);
            st[two].chmax(two, tot);
            st[two].chmax(one, tot);
            st[one].chmax(two, tot);
        } else {
            for (int j = 0; j < N; j++) {
                j_max[j] = st[j].maxrange(0, N);
            }
            for (int j = 0; j < 3; j++) {
                jj[j] = st[B[j]].get(B[j]);
            }
            for (int j = 0; j < 3; j++) {
                st[B[(j+1)%3]].chmax(B[(j+2)%3], jj[j] + 1);
                st[B[(j+2)%3]].chmax(B[(j+1)%3], jj[j] + 1);
            }
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 3; k++) {
                    st[B[k]].chmax(j, j_max[j]);
                    st[j].chmax(B[k], j_max[j]);
                }
            }
            int tot = 0;
            for (int j = 0; j < N; j++) tot = max(tot, j_max[j]);
            for (int j = 0; j < 3; j++) {
                st[B[j]].chmax(B[(j+1)%3], tot);
                st[B[(j+1)%3]].chmax(B[j], tot);
            }
        }
    }
    Int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, st[i].maxrange(0, N) + total);
    }
    ans = max(ans, st[A[3 * N - 1]].get(A[3 * N - 1]) + total + 1);
    cout << ans << endl;
    return 0;
}
