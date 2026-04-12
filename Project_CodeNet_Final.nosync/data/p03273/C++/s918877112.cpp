#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> A(100, vector<char>(100));

    rep(i, H) rep(j, W) cin >> A[i][j];

    vector<bool> rows(H,true), columns(W,true);

    rep(i,H) rep(j,W) {
        if(A[i][j] == '#'){
            rows[i] = false;
            columns[j] = false;
        }
    }

    rep(i,H){
        bool flag = false;
        rep(j,W){
            if(!rows[i] && !columns[j]){
                cout << A[i][j];
                flag = true;
            }
        }
        if(flag) cout << endl;
    }
}