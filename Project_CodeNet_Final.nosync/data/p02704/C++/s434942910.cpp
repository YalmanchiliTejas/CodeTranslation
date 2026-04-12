#include <bits/stdc++.h>

#define long uint64_t
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> opr(n);
    for (int i = 0; i < n; i++) {
        cin >> opr[i];
    }
    vector<int> opc(n);
    for (int i = 0; i < n; i++) {
        cin >> opc[i];
    }
    vector<long> valr(n);
    for (int i = 0; i < n; i++) {
        cin >> valr[i];
    }
    vector<long> valc(n);
    for (int i = 0; i < n; i++) {
        cin >> valc[i];
    }
    vector<vector<long>> res(n, vector<long>(n));
    for (int t = 0; t < 64; t++) {
//    for (int t = 0; t < 1; t++) {
        vector<int> bitr(n);
        for (int i = 0; i < n; i++) {
            bitr[i] = (valr[i] >> t) & 1;
        }
        vector<int> bitc(n);
        for (int i = 0; i < n; i++) {
            bitc[i] = (valc[i] >> t) & 1;
        }
        vector<vector<int>> a(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (opr[i] == 0 && bitr[i] == 1) {
                    if (a[i][j] == 0) {
                        cout << -1;
                        return 0;
                    }
                    a[i][j] = 1;
                }
                if (opr[i] == 1 && bitr[i] == 0) {
                    if (a[i][j] == 1) {
                        cout << -1;
                        return 0;
                    }
                    a[i][j] = 0;
                }
                if (opc[j] == 0 && bitc[j] == 1) {
                    if (a[i][j] == 0) {
                        cout << -1;
                        return 0;
                    }
                    a[i][j] = 1;
                }
                if (opc[j] == 1 && bitc[j] == 0) {
                    if (a[i][j] == 1) {
                        cout << -1;
                        return 0;
                    }
                    a[i][j] = 0;
                }
            }
        }
        vector<int> andr(n, 1), andc(n, 1), orr(n), orc(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != -1) {
                    andr[i] &= a[i][j];
                    andc[j] &= a[i][j];
                    orr[i] |= a[i][j];
                    orc[j] |= a[i][j];
                }
            }
        }

        vector<int> r0, r1, c0, c1, r2, c2;
        for (int i = 0; i < n; i++) {
            if (opr[i] == 0 && bitr[i] == 0 && andr[i] == 1) r0.push_back(i);
            if (opr[i] == 1 && bitr[i] == 1 && orr[i] == 0) r1.push_back(i);
            if (opc[i] == 0 && bitc[i] == 0 && andc[i] == 1) c0.push_back(i);
            if (opc[i] == 1 && bitc[i] == 1 && orc[i] == 0) c1.push_back(i);
            if (opr[i] == 0 && bitr[i] == 0 && andr[i] == 0) r2.push_back(i);
            if (opr[i] == 1 && bitr[i] == 1 && orr[i] == 1) r2.push_back(i);
            if (opc[i] == 0 && bitc[i] == 0 && andc[i] == 0) c2.push_back(i);
            if (opc[i] == 1 && bitc[i] == 1 && orc[i] == 1) c2.push_back(i);
        }

        if (r0.size() + r1.size() + r2.size() >= 2 &&
            c0.size() + c1.size() + c2.size() >= 2) {
            r0.insert(r0.end(), r1.begin(), r1.end());
            r0.insert(r0.end(), r2.begin(), r2.end());
            c0.insert(c0.end(), c1.begin(), c1.end());
            c0.insert(c0.end(), c2.begin(), c2.end());
            for (int i = 0; i < r0.size(); i++) {
                for (int j = 0; j < c0.size(); j++) {
                    a[r0[i]][c0[j]] = (i + j) & 1;
                }
            }
        } else if (r0.size() + r1.size() == 0 && c0.size() + c1.size() == 0) {
            // do nothing
        } else if (r0.size() + r1.size() + r2.size() == 0 ||
                   c0.size() + c1.size() + c2.size() == 0) {
            cout << -1;
            return 0;
        } else if (r0.size() + r1.size() + r2.size() == 1) {
            if (r0.size() > 0 && c0.size() + c2.size() == 0 ||
                r1.size() > 0 && c1.size() + c2.size() == 0) {
                cout << -1;
                return 0;
            }
            r0.insert(r0.end(), r1.begin(), r1.end());
            r0.insert(r0.end(), r2.begin(), r2.end());
            for (int j : c0) {
                a[r0[0]][j] = 0;
            }
            for (int j : c1) {
                a[r0[0]][j] = 1;
            }
            for (int j : c2) {
                a[r0[0]][j] = r1.size() > 0;
            }
        } else {
            if (c0.size() > 0 && r0.size() + r2.size() == 0 ||
                c1.size() > 0 && r1.size() + r2.size() == 0) {
                cout << -1;
                return 0;
            }
            c0.insert(c0.end(), c1.begin(), c1.end());
            c0.insert(c0.end(), c2.begin(), c2.end());
            for (int j : r0) {
                a[j][c0[0]] = 0;
            }
            for (int j : r1) {
                a[j][c0[0]] = 1;
            }
            for (int j : r2) {
                a[j][c0[0]] = c1.size() > 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == -1) a[i][j] = 0;
                res[i][j] += (long) a[i][j] << t;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}