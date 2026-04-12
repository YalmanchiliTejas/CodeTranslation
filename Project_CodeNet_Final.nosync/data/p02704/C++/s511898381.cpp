#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int n;
int u[500], v[500];
int res[500][500];

bool solve(int a, const vector<ull> &S, const vector<ull> &T, const vector<ull> &U, const vector<ull> &V) {
    rep(i, n) rep(j, n) res[i][j] = -1;
    rep(i, n) {
        u[i] = (U[i] >> a) & 1;
        v[i] = (V[i] >> a) & 1;
    }
    rep(i, n) rep(j, n) {
        if (!S[i] && u[i]) {
            if (T[j] && !v[j]) return false;
            res[i][j] = 1;
        } else if (S[i] && !u[i]) {
            if (!T[j] && v[j]) return false;
            res[i][j] = 0;
        } else if (T[j] && !v[j]) {
            res[i][j] = 0;
        } else if (!T[j] && v[j]) {
            res[i][j] = 1;
        }
    }

    rep(_, 2) {
        rep(i, n) {
            if (S[i] == !u[i]) continue;
            bool flg = false;
            vector<int> unk;
            rep(j, n) {
                if (res[i][j] == S[i]) flg = true;
                if (res[i][j] == -1) unk.push_back(j);
            }
            if (flg) continue;
            if (!unk.size()) return false;
            if (unk.size() == 1) res[i][unk[0]] = S[i];
        }
        rep(i, n) {
            if (T[i] == !v[i]) continue;
            bool flg = false;
            vector<int> unk;
            rep(j, n) {
                if (res[j][i] == T[i]) flg = true;
                if (res[j][i] == -1) unk.push_back(j);
            }
            if (flg) continue;
            if (!unk.size()) return false;
            if (unk.size() == 1) res[unk[0]][i] = T[i];
        }
    }
    vector<int> is, js;
    rep(i, n) {
        bool flg = true;
        rep(j, n) if (res[i][j]==-1) flg = false;
        if (!flg) is.push_back(i);
    }
    rep(i, n) {
        bool flg = true;
        rep(j, n) if (res[j][i]==-1) flg = false;
        if (!flg) js.push_back(i);
    }
    rep(i, is.size()) rep(j, js.size()) {
        res[is[i]][js[j]] = (i+j) % 2;
    }
    return true;
}

int main() {
    cin >> n;
    vector<ull> S(n), T(n), U(n), V(n);
    rep(i, n) cin >> S[i];
    rep(i, n) cin >> T[i];
    rep(i, n) cin >> U[i];
    rep(i, n) cin >> V[i];
    vector<vector<ull>> A(n, vector<ull>(n));
    rep(a, 64) {
        if (!solve(a, S, T, U, V)) {
            cout << -1 << endl;
            return 0;
        }
        rep(i, n) rep(j, n) A[i][j] |= ull(res[i][j]) << a;
    }
    rep(i, n) rep(j, n) {
        cout << A[i][j];
        if (j == n-1) cout << endl;
        else cout << " ";
    }
    return 0;
}