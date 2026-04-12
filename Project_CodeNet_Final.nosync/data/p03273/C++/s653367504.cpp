#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    char a[h][w];
    rep(i, h) rep(j, w) cin >> a[i][j];

    int rmh[h] = {0}, rmw[w] = {0};
    rep(i, h) {
        bool rm = true;
        rep(j, w) if (a[i][j] == '#') rm = false;
        if (rm) rmh[i] = 1;
    }

    rep(i, w) {
        bool rm = true;
        rep(j, h) if (a[j][i] == '#') rm = false;
        if (rm) rmw[i] = 1;
    }

    rep(i, h) {
        if (!rmh[i]) {
            rep(j, w) if (!rmw[j]) cout << a[i][j];
            cout << endl;
        }
    }

    return 0;
}
