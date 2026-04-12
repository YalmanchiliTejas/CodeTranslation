#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using vint = vector<int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> field(h);
    vector<string> field_1;
    vint index;
    rep(i,h) cin >> field[i];
    rep(i,h) {
        bool ok = false;
        rep(j,w) if (field[i][j] == '#') ok = true;
        if (ok) field_1.push_back(field[i]);
    }
    rep(i,w) {
        bool ok = false;
        rep(j,field_1.size()) if (field_1[j][i] == '#') ok = true;
        if (ok) index.push_back(i);
    }
    rep(i,field_1.size()) {
        rep(j,index.size()) {
            cout << field_1[i][index[j]];
        }
        cout << endl;
    }
}