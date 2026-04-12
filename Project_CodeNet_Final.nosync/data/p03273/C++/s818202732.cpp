#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w; cin >> h >> w;
    vector<string> a(h);
    vector<bool> hb(h);
    vector<bool> wb(w);
    rep(i, h) {
            cin >> a.at(i);
    }

    rep(i, h) {
        rep(j, a.at(i).size()) {
            if (a.at(i).at(j) == '#') {
                wb.at(j) = true;
                hb.at(i) = true;
            }
        }
    }

    rep(i, h) {
        bool flg = false;
        rep(j, a.at(i).size()) {
            if (hb.at(i) == true && wb.at(j) == true) {
                cout << a.at(i).at(j);
                flg = true;
            }
        }
        if (flg)
            cout << endl;
    }
    return 0;
}