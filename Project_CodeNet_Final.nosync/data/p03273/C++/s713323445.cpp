#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i, H) cin >> a[i];
    vector<bool> R(H, false), C(W, false);
    rep(i, H) {
        rep(j, W) {
            if (a[i][j] == '#') {
                R[i] = true;
                C[j] = true;
            }
        }
    }
    rep(i, H) {
        if (R[i]) {
            rep(j, W) {
                if (C[j]) cout << a[i][j];
            }
            cout << "\n";
        }
    }
}