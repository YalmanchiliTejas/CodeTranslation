#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i,H){
        cin >> a[i];
    }

    vector<bool> rows(H);
    vector<bool> cols(W);

    rep(i,H){
        bool is_white = true;
        for(int j=0; j<W; j++){
            if(a[i][j] == '#'){
                is_white = false;
                break;
            }
        }
        rows[i] = is_white;
    }

    rep(i,W){
        bool is_white = true;
        for(int j=0; j<H; j++){
            if(a[j][i] == '#'){
                is_white = false;
                break;
            }
        }
        cols[i] = is_white;
    }

    rep(i,H){
        if(rows[i])continue;
        for(int j=0; j<W; j++){
            if(cols[j]){continue;}
            cout << a[i][j];
        }
        cout << "" << endl;
    }

    return 0;
}