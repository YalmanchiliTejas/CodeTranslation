#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;

    string ai;
    vector<string> A(H);
    rep(i, H) cin >> A[i];

    bool row[H], col[W];
    rep(i, H) row[i] = false;
    rep(i, W) col[i] = false;

    rep(i, H) rep(j, W) {
        if (A[i][j] == '#') {
            row[i] = true;
            col[j] = true;
        }
    }

    rep(i, H) if (row[i]) {
        rep(j, W) if (col[j]) cout << A[i][j];
        cout << endl;
    }


    return 0;
}

