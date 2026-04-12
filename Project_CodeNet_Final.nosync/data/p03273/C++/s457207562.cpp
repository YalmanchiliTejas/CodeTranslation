#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main () {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    char in;
    cin >> H >> W;
    vector<vector<bool>> vv(H, vector<bool>(W));
    vector<bool> vvv(W, true);
    rep(i, H) {
        rep(j, W) {
            cin >> in;
            if(in == '#') {
                vv[i][j] = true;
            }
        }
    }
    bool b = false;
    for(int i = vv.size()-1; i >= 0; i--) {
        rep(j, vv[0].size()) {
            if(vv[i][j]) b = true;
        }
        if(!b)vv.erase(vv.begin() + i);
        b = false;
    }
    for(int i = vv[0].size()-1; i>= 0; i--) {
        rep(j, vv.size()) {
            if(vv[j][i]) b = true;
        }
        if(!b)vvv[i] = false;
        b = false;
    }
    rep(i, vv.size()) {
        rep(j, vv[0].size()) {
            if(!vvv[j]) continue;
            if(vv[i][j]) cout << '#';
            else cout << ".";
        }
        cout << endl;
    }
}