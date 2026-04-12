#include <bits/stdc++.h>
using namespace std;

int a[64][500][500];
uint64_t ans[500][500];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> s(n), t(n); 
    vector<uint64_t> u(n), v(n);
    uint64_t o = 1;
    for (auto &x: s) cin >> x;
    for (auto &x: t) cin >> x;
    for (auto &x: u) cin >> x;
    for (auto &x: v) cin >> x;
    bool ok = true;
    for (int k = 0; k < 64; k++) {
        vector<int> sv, tv;
        for (int i = 0; i < n; i++) {
            bool p = u[i] & (o << k);
            bool q = v[i] & (o << k);
            if (s[i] ^ p) {
                for (int j = 0; j < n; j++) {
                    if (a[k][i][j] == s[i] + 1) ok = false;
                    a[k][i][j] = 2 - s[i];
                }
            }
            if (t[i] ^ q) {
                for (int j = 0; j < n; j++) {
                    if (a[k][j][i] == t[i] + 1) ok = false;
                    a[k][j][i] = 2 - t[i];
                }
            }            
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool p = u[i] & (o << k);
                bool q = v[j] & (o << k);
                if (p == q) a[k][i][j] = p + 1;
            }
        }
        vector<int> rc(n, 0), cc(n, 0);
        for (int i = 0; i < n; i++) {       
            bool p = u[i] & (o << k);
            bool q = v[i] & (o << k);
            int c = 0, d = 0;
            for (int j = 0; j < n; j++) {
                c |= 1 << a[k][i][j];
                d |= 1 << a[k][j][i];
                if (a[k][i][j] == 0) rc[i]++, cc[j]++;
            }
            if (s[i] && p && !(c&4)) sv.emplace_back(i);
            if (t[i] && q && !(d&4)) tv.emplace_back(i);
            if (!s[i] && !p && !(c&3)) ok = false;
            if (!t[i] && !q && !(d&3)) ok = false;
            if (!s[i] && !p && !(c&2)) rc[i]--;
            if (!t[i] && !q && !(d&2)) cc[i]--;
        }
        for (auto &i: sv) {
            for (int j = 0; j < n; j++) {
                if (a[k][i][j] == 0 && cc[j] > 0) {
                    cc[j]--; a[k][i][j] = 2;
                    break;
                }
                if (j == n-1) ok = false; 
            }
        }
        for (auto &j: tv) {
            for (int i = 0; i < n; i++) {
                if (a[k][i][j] == 0 && rc[i] > 0) {
                    rc[i]--; a[k][i][j] = 2;
                    break;
                }
                if (i == n-1) ok = false; 
            }
        }
    }
    for (int k = 0; k < 64; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[k][i][j] == 2) ans[i][j] |= o << k;
            }
        }
    }
    if (!ok) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) cout << " ";
            cout << ans[i][j];
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        uint64_t q = ans[i][0];
        for (int j = 0; j < n; j++) {
            if (s[i]) q |= ans[i][j];
            else q &= ans[i][j];
        }
        assert(q == u[i]);
    }
    for (int i = 0; i < n; i++) {
        uint64_t q = ans[0][i];
        for (int j = 0; j < n; j++) {
            if (t[i]) q |= ans[j][i];
            else q &= ans[j][i];
        }
        assert(q == v[i]);
    }
    return 0;
}