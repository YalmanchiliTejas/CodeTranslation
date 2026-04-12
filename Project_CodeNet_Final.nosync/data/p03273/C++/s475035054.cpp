#include<bits/stdc++.h>
#define ll long long
#define REP(i, n) for (int i=0; i<n; ++i)
#define print(x) cout << x << endl;

using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<vector<char> > a(H, vector<char>(W));
    REP(i, H) {
        REP(j, W) {
            cin >> a[i][j];
        }
    }
    
    vector<int> newH, newW;
    REP(i, H) {
        bool flag = false;
        REP(j, W) {
            if (a[i][j] == '#') {
                flag = true;
                break;
            }
        }
        if (flag) {
            newH.push_back(i);
        }
    }
    REP(i, W) {
        bool flag = false;
        REP(j, H) {
            if (a[j][i] == '#') {
                flag = true;
                break;
            }
        }
        if (flag) {
            newW.push_back(i);
        }
    }

    for (int h = 0; h < newH.size(); h++) {
        for (int w = 0; w < newW.size(); w++) {
            cout << a[newH[h]][newW[w]];
        }
        cout << endl;
    }
}

int main() {

    solve();
    return 0;
}
