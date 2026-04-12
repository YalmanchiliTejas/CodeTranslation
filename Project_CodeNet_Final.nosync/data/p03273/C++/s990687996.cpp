#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;

const int MOD = 1000000007;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> m(H, vector<int>(W, 0));


    rep(i, H) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '#') m[i][j] = 1;
        }
    }

    vector<bool> h(H, false);
    vector<bool> w(W, false);

    rep(i, H) {
        bool ok = true;
        rep(j, W) {
            if (m[i][j] == 1) {
                ok = false;
                break;
            }
        }
        if (ok) h[i] = true;
    }

    rep(j, W) {
        bool ok = true;
        rep(i, H) {
            if (m[i][j] == 1) {
                ok = false;
                break;
            }
        }
        if (ok) w[j] = true;
    }

    rep(i, H) {
        if (h[i]) continue;
        rep(j, W) {
            if (w[j]) continue;
            if (m[i][j] == 1) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}