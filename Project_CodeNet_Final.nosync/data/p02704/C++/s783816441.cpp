#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, s[512] = {}, t[512] = {};
    unsigned long long u[512] = {}, v[512] = {}, z[512][512] = {};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < 64; i++) {
        int w[512][512] = {}, x[512] = {}, y[512] = {};
        for (int j = 0; j < n; j++) {
            if (u[j] & (1ull << i)) x[j] = 1;
            if (v[j] & (1ull << i)) y[j] = 1;
        }
        for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) w[j][k] = -1;
        for (int j = 0; j < n; j++) {
            if (!s[j] && x[j]) for (int k = 0; k < n; k++) w[j][k] = 1;
            if (s[j] && !x[j]) for (int k = 0; k < n; k++) w[j][k] = 0;
        }
        //if (!i) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) cout << w[j][k] << " \n"[k == n - 1];
        for (int j = 0; j < n; j++) {
            if (!t[j] && y[j]) for (int k = 0; k < n; k++) {
                if (w[k][j] == 0) {cout << -1; return 0;}
                w[k][j] = 1;
            }
            if (t[j] && !y[j]) for (int k = 0; k < n; k++) {
                if (w[k][j] == 1) {cout << -1; return 0;}
                w[k][j] = 0;
            }
        }
        //for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) cout << w[j][k] << " \n"[k == n - 1];
        vector<pii> a, b;
        for (int j = 0; j < n; j++) if (s[j] == x[j]) {
            bool r = 0;
            if (!s[j]) {for (int k = 0; k < n; k++) if (w[j][k] == 0) r = 1;}
            else {for (int k = 0; k < n; k++) if (w[j][k] == 1) r = 1;}
            if (!r) a.push_back({j, 0});
            else a.push_back({j, 1});
        }
        for (int j = 0; j < n; j++) if (t[j] == y[j]) {
            bool r = 0;
            if (!t[j]) {for (int k = 0; k < n; k++) if (w[k][j] == 0) r = 1;}
            else {for (int k = 0; k < n; k++) if (w[k][j] == 1) r = 1;}
            if (!r) b.push_back({j, 0});
            else b.push_back({j, 1});
        }
        if (i >= 0) {
            //for (pii j : a) cout << j.first << ',' << j.second << ' '; cout << '\n';
            //for (pii j : b) cout << j.first << ',' << j.second << ' '; cout << '\n';
        }
        if (a.size() > 1 && b.size() > 1) {
            for (int j = 0; j < a.size(); j++) for (int k = 0; k < b.size(); k++) w[a[j].first][b[k].first] = (j + k) % 2;
        } else if (!a.size() && !b.size()) {
            
        } else if (!a.size() && b.size()) {
            for (pii j : b) if (!j.second) {
                cout << -1;
                return 0;
            }
        } else if (a.size() && !b.size()) {
            for (pii j : a) if (!j.second) {
                cout << -1;
                return 0;
            }
        } else if (a.size() == 1) {
            bool p = 0, q = 0;
            for (pii j : b) {
                if (j.second) w[a[0].first][j.first] = s[a[0].first], p = q = 1;
                else if (!t[j.first]) w[a[0].first][j.first] = 0, p = 1;
                else w[a[0].first][j.first] = 1, q = 1;
            }
            if (!s[a[0].first]) {
                if (!p && !a[0].second) {
                    cout << -1;
                    return 0;
                }
            } else {
                if (!q && !a[0].second) {
                    cout << -1;
                    return 0;
                }
            }
        } else {
            bool p = 0, q = 0;
            for (pii j : a) {
                if (j.second) w[j.first][b[0].first] = t[b[0].first], p = q = 1;
                else if (!s[j.first]) w[j.first][b[0].first] = 0, p = 1;
                else w[j.first][b[0].first] = 1, q = 1;
            }
            if (!t[b[0].first]) {
                if (!p && !b[0].second) {
                    cout << -1;
                    return 0;
                }
            } else {
                if (!q && !b[0].second) {
                    cout << -1;
                    return 0;
                }
            }
        }
        for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) if (w[j][k] == 1) z[j][k] += (1ull << i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << z[i][j] << " \n"[j == n - 1];
    }
}
