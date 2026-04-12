#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i, H) cin >> a[i];
    rep(i, H) {
        bool f = true;
        rep(j, W) {
            if (a[i][j] == '#') f = false;
        }
        if (f) {
            rep(j, W) {
                a[i][j] = ' ';
            }
        }
    }
    rep(j, W) {
        bool f = true;
        rep(i, H) {
            if (a[i][j] == '#') f = false;
        }
        if (f) {
            rep(i, H) {
                a[i][j] = ' ';
            }
        }
    }
    rep(i, H) {
        bool f = false;
        rep(j, W) {
            if (a[i][j] != ' ') {
                cout << a[i][j];
                f = true;
            }
        }
        if (f) cout << "\n";
    }
}