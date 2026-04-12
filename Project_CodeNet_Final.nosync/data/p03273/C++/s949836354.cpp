#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> G(H);
    rep(i, H) cin >> G.at(i);
    vector<vector<string>> a(H, vector<string>(W));
    rep(i, H) rep(j, W) a.at(i).at(j) = G.at(i).at(j);

    rep(i, H) {
        bool flag = true;
        rep(j, W) if (a.at(i).at(j) == "#") flag = false;
        if (flag) rep(k, W) a.at(i).at(k) = "x";
    }

    rep(j, W) {
        bool flag = true;
        rep(i, H) if (a.at(i).at(j) == "#") flag = false;
        if (flag) rep(l, H) a.at(l).at(j) = "x";
    }

    rep(i, H) {
        bool flag = false;
        rep(j, W) {
            if (a.at(i).at(j) != "x") {
                cout << a.at(i).at(j);
                flag = true;
            }
        }
        if (flag) cout << endl;
    }

}