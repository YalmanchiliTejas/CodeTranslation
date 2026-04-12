#include <bits/stdc++.h>
using namespace std;

int h, w;
string ma[101];

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> ma[i];
    }

    bool r_rm[101] = {0, };
    for (int i = 0; i < h; i++) {
        bool white = true;
        for (int j = 0; j < w; j++) {
            if (ma[i][j] == '#') {
                white = false;
                break;
            }
        }
        if (white) {
            r_rm[i] = true;
        }
    }

    vector<string> n_ma;
    for (int i = 0; i < h; i++) {
        if (r_rm[i]) continue;
        n_ma.push_back(ma[i]);
    }

//    for (auto it : n_ma) cout << it << '\n';

    bool c_rm[101] = {0, };
    for (int j = 0; j < w; j++) {
        bool white = true;
        for (int i = 0; i < n_ma.size(); i++) {
            if (n_ma[i][j] == '#') {
                white = false;
                break;
            }
        }
        if (white) {
            c_rm[j] = true;
        }
    }

    for (int i = 0; i < n_ma.size(); i++) {
        for (int j = 0; j < w; j++) {
            if (c_rm[j]) continue;
            cout << n_ma[i][j];
        }
        cout << '\n';
    }


    return 0;
}
