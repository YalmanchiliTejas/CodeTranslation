#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W, '-'));

    rep(i, H) {
        rep(j, W) {
            cin >> a.at(i).at(j);
        }
    }

    vector<bool> row(H, false);
    vector<bool> col(W, false);

    rep(i, H) {
        rep(j, W) {
            if (a.at(i).at(j) == '#') {
                row.at(i) = true;
                col.at(j) = true;
            }
        }
    }

    rep(i, H) {
        if (row.at(i)) {
            rep(j, W) {
                if (col.at(j)) {
                    cout << a.at(i).at(j);
                }
            }
            cout << endl;
        }
    }
}
