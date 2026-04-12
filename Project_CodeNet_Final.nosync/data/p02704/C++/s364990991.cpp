#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    using ull = unsigned long long;
    int n;
    cin >> n;
    vector<int> s(n), t(n);
    vector<ull> u(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<ull>> ans(n, vector<ull>(n));
    bool ng = false;
    for (int msk = 0; msk < 64; msk++) {
        vector<vector<int>> x(n, vector<int>(n, -1));
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            if ((u[i] >> msk) & 1) {
                a[i] = 1;
            }
            if ((v[i] >> msk) & 1) {
                b[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != a[i]) {
                for (int j = 0; j < n; j++) {
                    if (x[i][j] == s[i]) {
                        ng = true;
                        break;
                    }
                    x[i][j] = a[i];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (t[i] != b[i]) {
                for (int j = 0; j < n; j++) {
                    if (x[j][i] == t[i]) {
                        ng = true;
                        break;
                    }
                    x[j][i] = b[i];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (x[i][j] == -1) {
                    if (a[i] == b[j]) {
                        x[i][j] = a[i];
                    } else {
                        x[i][j] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 1 && a[i] == 1) {
                bool ok = false;
                for (int j = 0; j < n; j++) {
                    if (x[i][j] == 1) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
                for (int j = 0; j < n; j++) {
                    if (t[j] == 0 && b[j] == 0) {
                        for (int k = 0; k < n; k++) {
                            if (k == i) continue;
                            if (!x[k][j]) {
                                ok = true;
                                break;
                            }
                        }
                        if (ok) {
                            x[i][j] = 1;
                            break;
                        }
                    }
                }
                if (ok) continue;
                ng = true;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (t[i] == 1 && b[i] == 1) {
                bool ok = false;
                for (int j = 0; j < n; j++) {
                    if (x[j][i] == 1) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
                for (int j = 0; j < n; j++) {
                    if (s[j] == 0 && a[j] == 0) {
                        for (int k = 0; k < n; k++) {
                            if (k == i) continue;
                            if (!x[j][k]) {
                                ok = true;
                                break;
                            }
                        }
                        if (ok) {
                            x[j][i] = 1;
                            break;
                        }
                    }
                }
                if (ok) continue;
                ng = true;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 0 && a[i] == 0) {
                for (int j = 0; j < n; j++) {
                    if (!x[i][j]) break;
                    if (j == n - 1) ng = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (t[i] == 0 && b[i] == 0) {
                for (int j = 0; j < n; j++) {
                    if (!x[j][i]) break;
                    if (j == n - 1) ng = true;
                }
            }
        }
        if (ng) {
            cout << -1 << '\n';
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (x[i][j] == 1) {
                    ans[i][j] += 1ULL << msk;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}