#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using ull = unsigned long long;
#define REP(i, n)    for (ll (i) = 0;   (i) < (n); ++(i))
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); ++(i))

template<typename T>
void PV(T &v) {
    int sz = v.size();
    for (int i = 0; i < sz; ++i) cout << v[i] << " \n"[i == sz - 1];
}

int f(int t, int n) { return (t << 1) + n; }
const int AND = 0;
const int OR_ = 1;
const int ANY = 2;
const int ALL_0 = f(OR_, 0);
const int ALL_1 = f(AND, 1);
const int ANY_0 = f(AND, 0);
const int ANY_1 = f(OR_, 1);
bool isall(int t) { return (t == ALL_0) or (t == ALL_1); }
bool isany(int t) { return (t == ANY_0) or (t == ANY_1); }


int N;
vector<int> S, T;
vector<ull> U, V;

void invalid() {
    cout << -1 << endl;
    exit(0);
}

vector<vector<int>> solve(vector<int> &u, vector<int> &v) {
    vector<vector<int>> res(N, vector<int>(N, -1));
    vector<int> tx(N), ty(N);
    REP(i, N) tx[i] = f(S[i], u[i]);
    REP(i, N) ty[i] = f(T[i], v[i]);
    vector<vector<pair<int, int>>> pr;
    REP(i, N) {
        vector<pair<int, int>> tmp;
        REP(j, N) {
            if (isall(tx[i]) and isall(ty[j])) {
                if (tx[i] == ty[j]) res[i][j] = (tx[i] == ALL_0) ? 0 : 1;
                else invalid();
            } else if (isall(tx[i])) {
                res[i][j] = (tx[i] == ALL_0) ? 0 : 1;
            } else if (isall(ty[j])) {
                res[i][j] = (ty[j] == ALL_0) ? 0 : 1;
            } else {
                tmp.emplace_back(i, j);
            }
        }
        if (tmp.size() == 0) continue;
        pr.emplace_back(tmp);
    }

    if (pr.size()) {
        int H = pr.size(), W = pr[0].size();
        if (H > 1 and W > 1) {
            REP(h, H) REP(w, W) {
                int x, y;
                tie(x, y) = pr[h][w];
                res[x][y] = (h + w) % 2;
            }
        } else if (H == 1) {
            int h = pr[0][0].first;
            REP(w, W) {
                int x, y;
                tie(x, y) = pr[0][w];
                bool has0 = false, has1 = false;
                REP(i, N) {
                    if (res[i][y] == 0) has0 = true;
                    if (res[i][y] == 1) has1 = true;
                }
                if ((has0 and ty[y] == ANY_0) or (has1 and ty[y] == ANY_1)) res[h][y] = ANY;
                else if (ty[y] == ANY_0) res[h][y] = 0;
                else if (ty[y] == ANY_1) res[h][y] = 1;
            }
            int need = (tx[h] == ANY_0) ? 0 : 1;
            bool valid = false;
            REP(j, N) {
                if (res[h][j] == ANY) res[h][j] = need;
                if (res[h][j] == need) valid = true;
            }
            if (not valid) invalid();
        } else {
            int w = pr[0][0].second;
            REP(h, H) {
                int x, y;
                tie(x, y) = pr[h][0];
                bool has0 = false, has1 = false;
                REP(j, N) {
                    if (res[x][j] == 0) has0 = true;
                    if (res[x][j] == 1) has1 = true;
                }
                if ((has0 and tx[x] == ANY_0) or (has1 and tx[x] == ANY_1)) res[x][w] = ANY;
                else if (tx[x] == ANY_0) res[x][w] = 0;
                else if (tx[x] == ANY_1) res[x][w] = 1;
            }
            int need = (ty[w] == ANY_0) ? 0 : 1;
            bool valid = false;
            REP(i, N) {
                if (res[i][w] == ANY) res[i][w] = need;
                if (res[i][w] == need) valid = true;
            }
            if (not valid) invalid();
        }
    }
    REP(i, N) REP(j, N) if (res[i][j] == -1) assert(false);
    REP(i, N) {
        int _0 = 0, _1 = 0;
        REP(j, N) ((res[i][j] == 0) ? _0 : _1)++;
        if ((tx[i] == ALL_0) and (_1 != 0)) invalid();
        if ((tx[i] == ALL_1) and (_0 != 0)) invalid();
        if ((tx[i] == ANY_0) and (_0 == 0)) invalid();
        if ((tx[i] == ANY_1) and (_1 == 0)) invalid();
    }
    REP(j, N) {
        int _0 = 0, _1 = 0;
        REP(i, N) ((res[i][j] == 0) ? _0 : _1)++;
        if ((ty[j] == ALL_0) and (_1 != 0)) invalid();
        if ((ty[j] == ALL_1) and (_0 != 0)) invalid();
        if ((ty[j] == ANY_0) and (_0 == 0)) invalid();
        if ((ty[j] == ANY_1) and (_1 == 0)) invalid();
    }
    return res;
}

signed main() {

    cin >> N;

    S.resize(N); for (auto& e: S) cin >> e;
    T.resize(N); for (auto& e: T) cin >> e;
    U.resize(N); for (auto& e: U) cin >> e;
    V.resize(N); for (auto& e: V) cin >> e;

    vector<vector<ull>> res(N, vector<ull>(N, 0ULL));
    REP(i, 64) {
        vector<int> u(N), v(N);
        REP(j, N) u[j] = (U[j] >> i) & 1, v[j] = (V[j] >> i) & 1;
        auto mat = solve(u, v);
        REP(j, N) REP(k, N) res[j][k] |= ull(mat[j][k]) << i;
    }

    REP(i, N) REP(j, N) cout << res[i][j] << " \n"[j == N - 1];

}
