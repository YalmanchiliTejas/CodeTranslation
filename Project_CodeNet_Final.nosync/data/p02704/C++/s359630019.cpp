#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> s(n), t(n);
    vector<ll> u(n), v(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    auto fail = [&]() {
        cout << -1 << '\n';
        exit(0);
    };
    for (ll sh = 0; sh < 64; sh++) {
        vector<vector<ll>> a(n, vector<ll>(n, -1));
        vector<int> g(n);
        vector<int> h(n);
        ll shift = (1LL << sh);
        auto set = [&](int x, int y, int z) {
            if (a[x][y] == (1 ^ z)) {
                fail();
            }
            a[x][y] = z;
        };
        for (int i = 0; i < n; i++) {
            if (u[i] & shift) {
                g[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (v[i] & shift) {
                h[i] = 1;
            }
        }
        vector<pair<int, int>> row;
        vector<pair<int, int>> col;
        for (int i = 0; i < n; i++) {
            if (s[i] == 0) {
                if (g[i] == 1) {
                    for (int j = 0; j < n; j++) {
                        set(i, j, 1);
                    }
                } else {
                    row.emplace_back(i, 0);
                }
            } else {
                if (g[i] == 0) {
                    for (int j = 0; j < n; j++) {
                        set(i, j, 0);
                    }
                } else {
                    row.emplace_back(i, 1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (t[i] == 0) {
                if (h[i] == 1) {
                    for (int j = 0; j < n; j++) {
                        set(j, i, 1);
                    }
                } else {
                    col.emplace_back(i, 0);
                }
            } else {
                if (h[i] == 0) {
                    for (int j = 0; j < n; j++) {
                        set(j, i, 0);
                    }
                } else {
                    col.emplace_back(i, 1);
                }
            }
        }
        auto check_row = [&](int i, int need) -> bool {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == need) {
                    return true;
                }
            }
            return false;
        };
        auto check_col = [&](int j, int need) -> bool {
            for (int i = 0; i < n; i++) {
                if (a[i][j] == need) {
                    return true;
                }
            }
            return false;
        };
        vector<pair<int, int>> rr;
        vector<pair<int, int>> cc;
        if (row.size() == 0 || col.size() == 0) {
            goto finish;
        }
        for (auto R: row) {
            if (check_row(R.first, R.second)) {
                for (auto j: col) {
                    a[R.first][j.first] = j.second;
                }
                for (auto i: row) {
                    if (i.first == R.first) continue;
                    a[i.first][col[0].first] = i.second;
                }
                goto finish;
            } else {
                rr.emplace_back(R);
            }
        }
        for (auto C: col) {
            if (check_col(C.first, C.second)) {
                for (auto i: row) {
                    a[i.first][C.first] = i.second;
                }
                for (auto j: col) {
                    if (j.first == C.first) continue;
                    a[row[0].first][j.first] = j.second;
                }
                goto finish;
            } else {
                cc.emplace_back(C);
            }
        }
        if (rr.size() == 0 || cc.size() == 0) continue;
        if (rr.size() == 1) {
            for (auto C: cc) {
                a[rr[0].first][C.first] = C.second;
            }
        } else if (cc.size() == 1) {
            for (auto R: rr) {
                a[R.first][cc[0].first] = R.second;
            }

        } else {
            for (int i = 2; i < rr.size(); i++) {
                a[rr[i].first][cc[0].first] = rr[i].second;
            }
            for (int j = 1; j < cc.size(); j++) {
                a[rr[0].first][cc[j].first] = cc[j].second;
            }
            a[rr[0].first][cc[0].first] = rr[0].second;
            a[rr[1].first][cc[0].first] = cc[0].second;
            a[rr[1].first][cc[1].first] = rr[1].second;
        }
        finish:
            {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (a[i][j] != 0) {
                            ans[i][j] += shift;
                        }
                    }
                }
            }

    }
    for (int i = 0; i < n; i++) {
        ll res = ans[i][0];
        for (int j = 0; j < n; j++) {
            if (s[i] == 0) res &= ans[i][j];
            else res |= ans[i][j];
        }
        if (res != u[i]) fail();
    }
    for (int j = 0; j < n; j++) {
        ll res = ans[0][j];
        for (int i = 0; i < n; i++) {
            if (t[j] == 0) res &= ans[i][j];
            else res |= ans[i][j];
        }
        if (res != v[j]) fail();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}
