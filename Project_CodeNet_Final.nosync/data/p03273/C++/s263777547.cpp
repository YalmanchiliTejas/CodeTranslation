#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    char a[h][w];
    rep(i, h) rep(j, w) cin >> a[i][j];

    char res[h][w];
    int h_con = 0;
    int w_con = 0;

    //horizontal axis
    rep(i, h){
        bool drop_flg = true;
        rep(j, w){
            if(a[i][j]=='.') drop_flg = (drop_flg && true);
            else drop_flg = false;
        }
        if(drop_flg) {
            ++h_con;
            if(i != h-1) rep(j, w) res[i][j] = a[i+1][j];
        }
        else rep(j, w) res[i-h_con][j] = a[i][j];
    }

    char res2[h][w];
    //vertical axis
    rep(j, w){
        bool drop_flg = true;
        rep(i, h-h_con){
            if(res[i][j]=='.') drop_flg = (drop_flg && true);
            else drop_flg = false;
        }
        if(drop_flg) {
            ++w_con;
            if(j != w-1) rep(i, h-h_con) res2[i][j] = res[i][j+1];
        }
        else rep(i, h-h_con) res2[i][j-w_con] = res[i][j];
    }


    rep(i, h-h_con){
        rep(j, w-w_con) cout << res2[i][j];
        cout << endl;
    }
}