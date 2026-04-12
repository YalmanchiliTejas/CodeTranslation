#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define int long long
#define rep(n, i) for (int i = 0; i < n; i++)
#define rep2(m, n, i) for (int i = m; i < n; i++)
#define rep_r(n, i) for (int i = n - 1; i >= 0; i--)

const int INF = 1LL << 60;
const int MOD = 1e9 + 7;
const int MAX = 101;

int h, w;
char a[MAX][MAX];

bool dot_h(int n) {
    rep(w, j) {
        if (a[n][j] == '#') {
            return false;
        }
    }
    return true;
}

bool dot_w(int n) {
    rep(h, i) {
        if (a[i][n] == '#') {
            return false;
        }
    }
    return true;
}

signed main() {
    cin >> h >> w;
    rep(h, i) {
        rep(w, j) {
            cin >> a[i][j];
        }
    }
    bool remove[h][w];
    rep(h, i) {
        rep(w, j) {
            remove[i][j] = false;
        }
    }
    rep(h, i) {
        if (dot_h(i)) {
            rep(w, j) {
                remove[i][j] = true;
            }
        }
    }
    rep(w, j) {
        if (dot_w(j)) {
            rep(h, i) {
                remove[i][j] = true;
            }
        }
    }
    rep(h, i) {
        rep(w, j) {
            if (!remove[i][j]) {
                cout << a[i][j];
            }
        }
        if (!dot_h(i)) cout << endl;
    }
    return 0;
}