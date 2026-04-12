#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define debug(...)                                                             \
    { cerr << "# " << __VA_ARGS__ << "\n"; }
#else
#define debug(...)
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
typedef unsigned long long ui64;
const i64 MOD = 119 << 23 | 1;
class {
  public:
    ui64 a[555][555];
    ui64 b[555][555];
    bool s[555], t[555];
    ui64 u[555], v[555];
    int n;
    void solve() {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        for (int i = 0; i < n; ++i)
            cin >> t[i];
        for (int i = 0; i < n; ++i)
            cin >> u[i];
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        for (ui64 q = 0; q <= 63; ++q) {
            memset(b, 0, sizeof b);
            vector<int> chance(n);
            for (int i = 0; i < n; ++i) {
                if (u[i] >> q & 1ull) {
                    if (s[i])
                        chance[i] = n - 1;
                    for (int j = 0; j < n; ++j)
                        b[i][j] = 1;
                } else {
                    if (!s[i])
                        chance[i] = n - 1;
                }
            }
            for (int i = 0; i < n; ++i) {
                if ((v[i] >> q & 1ull) && t[i] == 0) {
                    for (int j = 0; j < n; ++j) {
                        if (b[j][i] == 1)
                            continue;
                        else {
                            b[j][i] = 1;
                            chance[j]--;
                            if (chance[j] < 0) {
                                cout << -1;
                                return;
                            }
                        }
                    }
                } else if (!(v[i] >> q & 1ull) && t[i] == 1) {
                    for (int j = 0; j < n; ++j) {
                        if (b[j][i] == 0)
                            continue;
                        else {
                            b[j][i] = 0;
                            chance[j]--;
                            if (chance[j] < 0) {
                                cout << -1;
                                return;
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                if (t[i] && (v[i] >> q & 1ull)) {
                    ui64 f = b[0][i];
                    for (int j = 1; j < n; ++j)
                        f |= b[j][i];
                    if (f == 1)
                        continue;
                    int maxchaid = 0;
                    for (int j = 0; j < n; ++j) {
                        if (chance[j] > chance[maxchaid]) {
                            maxchaid = j;
                        }
                    }
                    if (chance[maxchaid] == 0) {
                        cout << -1;
                        return;
                    }
                    b[maxchaid][i] = 1;
                    chance[maxchaid]--;
                } else if (!(v[i] >> q & 1ull) && !t[i]) {
                    ui64 f = b[0][i];
                    for (int j = 1; j < n; ++j)
                        f &= b[j][i];
                    if (f == 0)
                        continue;
                    int maxchaid = 0;
                    for (int j = 0; j < n; ++j) {
                        if (chance[j] > chance[maxchaid]) {
                            maxchaid = j;
                        }
                    }
                    if (chance[maxchaid] == 0) {
                        cout << -1;
                        return;
                    }
                    b[maxchaid][i] = 0;
                    chance[maxchaid]--;
                }
            }
            for (int ii = 0; ii < n; ++ii)
                for (int jj = 0; jj < n; ++jj)
                    a[ii][jj] |= b[ii][jj] << q;
        }
        for (int i = 0; i < n; ++i) {
            ui64 f;
            if (s[i]) {
                f = a[i][0];
                for (int j = 1; j < n; ++j)
                    f |= a[i][j];
            } else {
                f = a[i][0];
                for (int j = 1; j < n; ++j)
                    f &= a[i][j];
            }
            if (f != u[i]) {
                cout << -1;
                return;
            }
        }
        for (int i = 0; i < n; ++i) {
            ui64 f;
            if (t[i]) {
                f = a[0][i];
                for (int j = 1; j < n; ++j)
                    f |= a[j][i];
            } else {
                f = a[0][i];
                for (int j = 1; j < n; ++j)
                    f &= a[j][i];
            }
            if (f != v[i]) {
                cout << -1;
                return;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
} NSPACE;
int main() {
    FPEN;
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    NSPACE.solve();
}