#include <bits/stdc++.h>
using namespace std;
using lint     = unsigned long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    vector<lint> u(n), v(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<vector<lint>> ret(n, vector<lint>(n, 0));
    for (int i = 0; i < 64; ++i) {
        lint bit = 1ULL << i;
        vector<int> tu(n), tv(n);
        for (int k = 0; k < n; ++k) {
            tu[k] = u[k] >> i & 1;
            tv[k] = v[k] >> i & 1;
        }
        vector<vector<int>> temp(n, vector<int>(n, -1));
        vector<int> doneu(n, false), donev(n, false);
        bool zerorow = false, zerocol = false, onerow = false, onecol = false;
        int nrow = n, ncol = n;
        for (int k = 0; k < n; ++k) {
            if (tu[k] && !s[k]) {
                temp[k].assign(n, 1);
                doneu[k] = true;
                nrow--;
                onerow = true;
            }
            if (!tu[k] && s[k]) {
                temp[k].assign(n, 0);
                doneu[k] = true;
                nrow--;
                zerorow = true;
            }
        }
        for (int k = 0; k < n; ++k) {
            if (tv[k] && !t[k]) {
                for (int l = 0; l < n; ++l) {
                    if (temp[l][k] == 0) {
                        cout << -1 << "\n";
                        return 0;
                    }
                    temp[l][k] = 1;
                }
                onecol   = true;
                donev[k] = true;
                ncol--;
            }
            if (!tv[k] && t[k]) {
                for (int l = 0; l < n; ++l) {
                    if (temp[l][k] == 1) {
                        cout << -1 << "\n";
                        return 0;
                    }
                    temp[l][k] = 0;
                }
                zerocol  = true;
                donev[k] = true;
                ncol--;
            }
        }

        if (nrow == 1) {
            int ir = -1;
            for (int j = 0; j < n; ++j) {
                if (!doneu[j])
                    ir = j;
            }
            for (int j = 0; j < n; ++j) {
                if (donev[j])
                    continue;
                if (t[j] == 0 && tv[j] == 0) { // need one 0
                    if (!zerorow)
                        temp[ir][j] = 0;
                } else {
                    if (!onerow)
                        temp[ir][j] = 1;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (temp[ir][j] == tu[ir] || temp[ir][j] == -1) {
                    temp[ir][j] = tu[ir];
                    break;
                }
            }
        } else if (ncol == 1) {
            int ic = -1;
            for (int j = 0; j < n; ++j) {
                if (!donev[j])
                    ic = j;
            }
            for (int j = 0; j < n; ++j) {
                if (doneu[j])
                    continue;
                if (tu[j] == 0) {
                    if (!zerocol)
                        temp[j][ic] = 0;
                } else {
                    if (!onecol)
                        temp[j][ic] = 1;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (temp[j][ic] == tv[ic] || temp[j][ic] == -1) {
                    temp[j][ic] = tv[ic];
                    break;
                }
            }
        } else if (nrow > 1 && ncol > 1) {
            int idxj = 0;
            for (int j = 0; j < n; ++j) {
                int idxk = 0;
                if (doneu[j])
                    continue;
                for (int k = 0; k < n; ++k) {
                    if (donev[k])
                        continue;
                    temp[j][k] = (idxj % 2) ^ (idxk % 2);
                    idxk++;
                }
                idxj++;
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ret[j][k] += bit * (temp[j][k] == 1 ? 1 : 0);
            }
        }
    }
    // check
    for (int i = 0; i < n; ++i) {
        lint res = ret[i][0];
        if (s[i] == 0) {
            for (int j = 1; j < n; ++j) {
                res &= ret[i][j];
            }
        } else {
            for (int j = 1; j < n; ++j) {
                res |= ret[i][j];
            }
        }
        if (res != u[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        lint res = ret[0][i];
        if (t[i] == 0) {
            for (int j = 1; j < n; ++j) {
                res &= ret[j][i];
            }
        } else {
            for (int j = 1; j < n; ++j) {
                res |= ret[j][i];
            }
        }
        if (res != v[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    // ok!
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j)
                cout << " ";
            cout << ret[i][j];
        }
        cout << "\n";
    }
    return 0;
}