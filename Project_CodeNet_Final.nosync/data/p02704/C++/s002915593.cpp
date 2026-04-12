#include <bits/stdc++.h>
using namespace std;
#define int long
using u64 = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
void end() {
    cout << -1 << endl;
    exit(0);
}
signed main() {
    int n, m = 0;
    cin >> n;
    vector<int> s(n), t(n);
    vector<u64> ou(n), ov(n);
    vector<vector<bool>> u(64, vector<bool>(n, false)), v(u);
    for (auto& i : s) cin >> i;
    for (auto& i : t) cin >> i;
    for (auto& i : ou) cin >> i;
    for (auto& i : ov) cin >> i;
    rep(i, n) {
        u64 x, y;
        x = ou[i];
        y = x;
        rep(j, m) y /= 2;
        while (y > 0) y /= 2, ++m;
        for (int b = 0; x > 0; ++b, x >>= 1) u[b][i] = x & 1;
    }
    rep(i, n) {
        u64 x, y;
        x = ov[i];
        y = x;
        rep(j, m) y /= 2;
        while (y > 0) y /= 2, ++m;
        for (int b = 0; x > 0; ++b, x /= 2) v[b][i] = x & 1;
    }
    vector<vector<vector<int>>> a(64, vector<vector<int>>(n, vector<int>(n, -1)));
    rep(b, m) {
        vector<int> us, ut;
        rep(i, n) {
            if (s[i] && !u[b][i])
                rep(x, n) a[b][i][x] = 0;
            else if (!s[i] && u[b][i])
                rep(x, n) a[b][i][x] = 1;
            else
                us.push_back(i);
        }
        rep(i, n) {
            if (t[i] && !v[b][i]) {
                rep(x, n) {
                    if (a[b][x][i] == 1) end();
                    a[b][x][i] = 0;
                }
            } else if (!t[i] && v[b][i]) {
                rep(x, n) {
                    if (a[b][x][i] == 0) end();
                    a[b][x][i] = 1;
                }
            } else {
                rep(x, n) {
                    if (a[b][x][i] < 0) {
                        ut.push_back(i);
                        break;
                    }
                }
            }
        }
        if (us.size() > 1 && ut.size() > 1) {
            rep(i, us.size()) {
                rep(j, ut.size()) {
                    a[b][us[i]][ut[j]] = (i + j) % 2;
                }
            }
            continue;
        }
        if (ut.size() == 0)
            continue;
        else if (us.size() > 1) {
            int lor = 0, land = 0, col = ut[0];
            for (auto i : us) {
                if (s[i])
                    ++lor;
                else
                    ++land;
            }
            if (land == 0 && !t[col]) {
                bool filled = false;
                for (auto i : us) {
                    rep(j, n) {
                        if (a[b][i][j] == 1) {
                            a[b][i][col] = 0;
                            filled = true;
                            break;
                        }
                    }
                    if (filled) break;
                }
                if (!filled) end();
            }
            if (lor == 0 && t[col]) {
                bool filled = false;
                for (auto i : us) {
                    rep(j, n) {
                        if (a[b][i][j] == 0) {
                            a[b][i][col] = 1;
                            filled = true;
                            break;
                        }
                    }
                    if (filled) break;
                }
                if (!filled) end();
            }
            for (auto i : us) {
                if (s[i]) {
                    if (a[b][i][col] < 0) a[b][i][col] = 1;
                } else {
                    if (a[b][i][col] < 0) a[b][i][col] = 0;
                }
            }
        } else if (ut.size() > 1) {
            int lor = 0, land = 0, row = us[0];
            for (auto i : ut) {
                if (t[i])
                    ++lor;
                else
                    ++land;
            }
            if (!land && !s[row]) {
                bool filled = false;
                rep(i, n) {
                    for (auto j : ut) {
                        if (a[b][i][j] == 1) {
                            a[b][row][j] = 0;
                            filled = true;
                            break;
                        }
                    }
                    if (filled) break;
                }
                if (!filled) end();
            }
            if (!lor && s[row]) {
                bool filled = false;
                rep(i, n) {
                    for (auto j : ut) {
                        if (a[b][i][j] == 0) {
                            a[b][row][j] = 1;
                            filled = true;
                            break;
                        }
                    }
                    if (filled) break;
                }
                if (!filled) end();
            }
            for (auto i : ut) {
                if (t[i]) {
                    if (a[b][row][i] < 0) a[b][row][i] = 1;
                } else {
                    if (a[b][row][i] < 0) a[b][row][i] = 0;
                }
            }
        } else {
            int row = us[0], col = ut[0];
            int ls = s[row], lt = t[col], lu = u[b][row], lv = v[b][col];
            if (lu == lv)
                a[b][row][col] = lu;
            else if (n == 1)
                end();
            else {
                bool sres = (!ls ? 1 : 0), tres = (!lt ? 1 : 0);
                for (int i = 0; i < n; ++i) {
                    if (a[b][row][i] >= 0) sres = (!ls ? sres && a[b][row][i] : sres || a[b][row][i]);
                    if (a[b][i][col] >= 0) tres = (!lt ? tres && a[b][i][col] : tres || a[b][i][col]);
                }
                bool bres = false;
                sres = (!ls ? sres && bres : sres || bres);
                tres = (!lt ? tres && bres : tres || bres);
                if (sres == lu && tres == lv) {
                    a[b][row][col] = bres;
                    continue;
                }
                bres = true;
                sres = (!ls ? sres && bres : sres || bres);
                tres = (!lt ? tres && bres : tres || bres);
                if (sres == lu && tres == lv) {
                    a[b][row][col] = bres;
                    continue;
                }
                end();
            }
        }
    }
    vector<vector<u64>> res(n, vector<u64>(n, 0));
    rep(i, n) {
        rep(j, n) {
            for (int b = m - 1; b >= 0; --b) {
                res[i][j] *= 2;
                res[i][j] += (a[b][i][j] ? 1 : 0);
            }
        }
    }
    rep(i, n) {
        u64 sacc = res[i][0];
        for (int j = 1; j < n; ++j) sacc = (!s[i] ? sacc & res[i][j] : sacc | res[i][j]);
        if (sacc != ou[i]) end();
    }
    rep(i, n) {
        u64 tacc = res[0][i];
        for (int j = 1; j < n; ++j) tacc = (!t[i] ? tacc & res[j][i] : tacc | res[j][i]);
        if (tacc != ov[i]) end();
    }
    for (auto w : res) {
        for (auto i : w) {
            cout << i << " ";
        }
        cout << endl;
    }
}