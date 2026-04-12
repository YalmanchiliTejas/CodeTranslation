#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)
#define rrep(i, n) for(int i = ((int)n - 1); i >= 0; --i)

using ll = long long;
using ld = long double;

const ll INF = 1e18;
const int Inf = 1e9;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep (i, h) cin >> s[i];
    vector<vector<int> > g(h, vector<int>(w, -1));
    rep (i, h) {
        rep (j, w) {
            if (s[i][j] == '#') {
                g[i][j] = 1;
                continue;
            }
            bool ok = true;
            rep (k, h) {
                if (s[k][j] == '#') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                rep (k, h) g[k][j] = 0;
            }
            ok = true;
            rep (k, w) {
                if (s[i][k] == '#') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                rep (k, w) g[i][k] = 0;
            }
        }
    }

    rep (i, h) {
        bool exist = false;
        rep (j, w) {
            if (g[i][j] != 0) {
                cout << s[i][j];
                exist = true;
            }
        }
        if (exist) cout << endl;
    }
    
    return 0;
}

