#include <bits/stdc++.h>
using namespace std;
using UInt = unsigned long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
vector<vector<int>> f(const vector<int> &S, const vector<int> &T, const vector<int> &u, const vector<int> &v) {
    int N = S.size();
    vector<vector<int>> ans(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((S[i] == 0 && u[i] == 1) || (T[j] == 0 && v[j] == 1)
                || (S[i] == 1 && u[i] == 1 && T[j] == 1 && v[j] == 1)) {
                ans[i][j] = 1;
            }
            if ((S[i] == 1 && u[i] == 0) || (T[j] == 1 && v[j] == 0)
               || (S[i] == 0 && u[i] == 0 && T[j] == 0 && v[j] == 0)) {
                ans[i][j] = 0;
            }
        }
    }
    vector<int> i0, i1, j0, j1;
    for (int i = 0; i < N; i++) {
        if (S[i] == 0 && u[i] == 0) i0.push_back(i);
        if (S[i] == 1 && u[i] == 1) i1.push_back(i);
    }
    for (int j = 0; j < N; j++) {
        if (T[j] == 0 && v[j] == 0) j0.push_back(j);
        if (T[j] == 1 && v[j] == 1) j1.push_back(j);
    }
    bool done = false;
    for (int i : i0) {
        for (int j = 0; j < N; j++) if (ans[i][j] == 0) done = true;
        if (done) {
            for (int I : i0) for (int J : j1) ans[I][J] = (i == I ? 1 : 0);
            break;
        }
    }
    if (!done) for (int j : j1) {
        for (int i = 0; i < N; i++) if (ans[i][j] == 1) done = true;
        if (done) {
            for (int I : i0) for (int J : j1) ans[I][J] = (j == J ? 0 : 1);
            break;
        }
    }
    if (!done) {
        for (int a = 0; a < i0.size(); a++) {
            for (int b = 0; b < j1.size(); b++) {
                ans[i0[a]][j1[b]] = (a + b) % 2;
            }
        }
    }
    done = false;
    for (int i : i1) {
        for (int j = 0; j < N; j++) if (ans[i][j] == 1) done = true;
        if (done) {
            for (int I : i1) for (int J : j0) ans[I][J] = (i == I ? 0 : 1);
            break;
        }
    }
    if (!done) for (int j : j0) {
        for (int i = 0; i < N; i++) if (ans[i][j] == 0) done = true;
        if (done) {
            for (int I : i1) for (int J : j0) ans[I][J] = (j == J ? 1 : 0);
            break;
        }
    }
    if (!done) {
        for (int a = 0; a < i1.size(); a++) {
            for (int b = 0; b < j0.size(); b++) {
                ans[i1[a]][j0[b]] = (a + b) % 2;
            }
        }
    }
    return ans;
}
int main() {
    int N; cin >> N;
    vector<int> S(N), T(N);
    vector<UInt> U(N), V(N);
    for (auto &s : S) cin >> s;
    for (auto &t : T) cin >> t;
    for (auto &u : U) cin >> u;
    for (auto &v : V) cin >> v;
    vector ans(N, vector(N, 0ULL));
    for (int i = 0; i < 64; i++) {
        vector<int> u(N), v(N);
        for (int j = 0; j < N; j++) {
            u[j] = !!(U[j] & (1ULL << i));
            v[j] = !!(V[j] & (1ULL << i));
        }
        auto res = f(S, T, u, v);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                ans[j][k] |= ((UInt)res[j][k] << i);
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < N; i++) {
        UInt a = -1, o = 0;
        for (int j = 0; j < N; j++) {
            a &= ans[i][j];
            o |= ans[i][j];
        }
        ok &= ((S[i] == 0 ? a : o) == U[i]);
    }
    for (int j = 0; j < N; j++) {
        UInt a = -1, o = 0;
        for (int i = 0; i < N; i++) {
            a &= ans[i][j];
            o |= ans[i][j];
        }
        ok &= ((T[j] == 0 ? a : o) == V[j]);
    }
    if (!ok) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << ans[i][j] << " \n"[j + 1 == N];
            }
        }
    }
    return 0;
}
