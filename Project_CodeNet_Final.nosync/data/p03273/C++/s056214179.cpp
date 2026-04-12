// 7/12
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    rep(i, H) cin >> field[i];

    vector<bool> use_h(H, true), use_w(W, true);

    rep(h, H) {
        bool ok = true;
        rep(w, W) {
            if (field[h][w] == '#') {
                ok = false;
                break;
            }
        }
        if (ok) {
            use_h[h] = false;
        }
    }

    rep(w, W) {
        bool ok = true;
        rep(h, H) {
            if (field[h][w] == '#') {
                ok = false;
                break;
            }
        }
        if (ok) {
            use_w[w] = false;
        }
    }

    rep(h, H) {
        rep(w, W) {
            if (use_h[h] && use_w[w]) cout << field[h][w];
        }
        if (use_h[h]) cout << endl;
    }
    return 0;
}