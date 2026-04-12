#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    // 入力受け取り
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<bool> Horizon(H, false);   // 全て白の行をtrue
    vector<bool> Vertiacal(W, false); // 全て白の列をtrue
    
    // 行について、白かどうか調べる
    for (int i = 0; i < H; i++) {
        bool judge = true;  // 黒があったらfalse
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                judge = false;
            }
        }
        if (judge) {
            Horizon[i] = true;
        }
    }
    
    // 同様に列について調べる(添え字注意)
    for (int j = 0; j < W; j++) {
        bool judge = true;
        for (int i = 0; i < H; i++) {
            if (a[i][j] == '#') {
                judge = false;
            }
        }
        if (judge) {
            Vertiacal[j] = true;
        }
    }
    
    // 全て白の行または列は出力しない
    for (int i = 0; i < H; i++) {
        if (Horizon[i]) {
            continue;         // 全て白の行は出力しないのでcontinue
        } else {
            for (int j = 0; j < W; j++) {
                if (Vertiacal[j]) {
                    continue; // 全て白の列は出力しないのでcontinue
                } else {
                    cout << a[i][j];
                }
            }
        }
        cout << endl;  // 改行を忘れない
    }
}