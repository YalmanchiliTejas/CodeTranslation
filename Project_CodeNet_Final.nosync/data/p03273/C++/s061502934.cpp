#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> map(H, vector<char>(W));
 
    rep(i, H) rep(j, W) cin >> map[i][j];

    vector<bool> raw(H,true), column(W,true);
    rep(i,H) rep(j,W) {
        if(map.at(i).at(j) == '#'){
            raw.at(i) = false;
            column.at(j) = false;
        }
    }
    rep(i,H) {
        bool f = false;
        rep(j,W) {
            if(!raw.at(i) && !column.at(j)){
                cout << map.at(i).at(j);
                f = true;
            }
        }
        if(f) cout << endl;
    }
}
