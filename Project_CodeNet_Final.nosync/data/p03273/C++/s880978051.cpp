#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

int main(){
    int H,W; cin >> H >> W;
    char field[H][W];
    char c[H][W];

    for(int i=0; i<H; i++) for(int j=0; j<W; j++) cin >> c[i][j];

    int height = 0;
    for(int i=0; i<H; i++){
        bool flg = false;
        for(int j=0; j<W; j++) if(c[i][j] == '#') flg = true;

        if(flg){
            for(int j=0; j<W; j++) field[height][j] = c[i][j];
            height++;
        }
    }

    // for(int i=0; i<height; i++){
    //     for(int j=0; j<W; j++) cout << field[i][j];
    //     cout << endl;
    // }

    vector<int> omit;
    for(int j=0; j<W; j++){
        bool flg = false;
        for(int i=0; i<height; i++) if(field[i][j] == '#') flg = true;
        if(!flg) omit.push_back(j);
    }

    for(int i=0; i<height; i++){
        for(int j=0; j<W; j++){

            bool flg = true;
            for(int k=0; k<omit.size(); k++) if(j == omit[k]) flg = false;

            if(flg) cout << field[i][j];
        }
        cout << endl;
    }

}