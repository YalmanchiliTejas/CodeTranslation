#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int H, W; cin >> H >> W;
    vector<string> G(H);
    int cnt = 0;
    rep(i, H) {
        cin >> G.at(i);
        rep(j, G[i].size()) if (G[i][j] == '#') cnt++;
    }
    if (cnt == H + W - 1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}