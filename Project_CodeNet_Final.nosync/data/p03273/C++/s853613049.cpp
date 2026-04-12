#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (ll i = 0; i < H; i++) {
        cin >> a[i];
    }

    vector<bool> all_white_raw(H, true), all_white_col(W, true);
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                all_white_raw[i] = false;
                all_white_col[j] = false;
            }
        }
    }

    for (ll i = 0; i < H; i++) {
        if (all_white_raw[i]) {
            continue;
        }
        for (ll j = 0; j < W; j++) {
            if (all_white_col[j]) {
                continue;
            }
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}