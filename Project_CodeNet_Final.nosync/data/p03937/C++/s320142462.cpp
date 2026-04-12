#include "bits/stdc++.h"
using namespace std;

void solve() {
    int H, W, count = 0;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) {
        cin >> A.at(i);
        for (int j = 0; j < W; j++) if (A.at(i).at(j) == '#') count++;
    }
    if (count != H + W - 1) {
        cout << "Impossible" << endl;
        return;
    }
    int i = 0, j = 0;
    while (i < H - 1 || j < W - 1) {
        bool r = false, d = false;
        if (i < H - 1 && A.at(i + 1).at(j) == '#') d = true;
        if (j < W - 1 && A.at(i).at(j + 1) == '#') r = true;
        if (!(d ^ r)) {
            cout << "Impossible" << endl;
            return;
        }
        if (d) i++;
        if (r) j++;
    }
    cout << "Possible" << endl;
    return;
}

int main() {
    solve();
}