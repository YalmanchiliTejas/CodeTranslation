#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> a[i][j];
    
    vector<bool> h(H, true), w(W, true);
    rep(i, H) {
        bool judge = true;
        rep(j, W) {
            if (a[i][j] == '#') judge = false;
        }
        h[i] = judge;
    }
    rep(i, W) {
        bool judge = true;
        rep(j, H) {
            if (a[j][i] == '#') judge = false;
        }
        w[i] = judge;
    }
    
    rep(i, H) rep(j, W) {
        if (!(h[i] || w[j])) cout << a[i][j];
        if (j == W - 1 && !h[i]) cout << endl;
    }
    return 0;
}
