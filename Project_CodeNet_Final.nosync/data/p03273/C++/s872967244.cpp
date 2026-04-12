#include <bits/stdc++.h>
using namespace std;

int main() {
    //縦横の入力
    int H, W;
    cin >> H >> W;
    //二次配列作成
    vector<vector<char>> date(H, vector<char> (W));
    //初期値をfalse(bool値の為、charの初期値に出来ない為ここで書く)
    vector<bool> tate(H, false);
    vector<bool> yoko(W, false);
    //dateの入力
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> date.at(i).at(j);
        }
    }
    //date(i,j)が＃なら真に
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (date.at(i).at(j) == '#') {
                tate.at(i) = true;
                yoko.at(j) = true;
            }
        }
    }
    //もしある縦(i)が真で、その配列(横)(j)も真なら
    for (int i = 0; i < H; i++) {
        if (tate.at(i)) {
            for (int j = 0; j < W; j++) {
                if (yoko.at(j)) {
                    cout << date.at(i).at(j);
                }
            }
            cout << endl;
        }
    }

}