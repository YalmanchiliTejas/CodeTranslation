#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    REP(i, H) cin >> a[i];

    vector<int> I, J;
    REP(i, H) {
        bool has_black = false;
        REP(j, W) {
            if (a[i][j] == '#') {
                has_black = true;
                break;
            }
        }
        if (has_black) {
            I.push_back(i);
        }
    }
    REP(j, W) {
        bool has_black = false;
        REP(i, H) {
            if (a[i][j] == '#') {
                has_black = true;
                break;
            }
        }
        if (has_black) {
            J.push_back(j);
        }
    }

    for (int i: I) {
        for (int j: J) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    cout << flush;

    return 0;
}
