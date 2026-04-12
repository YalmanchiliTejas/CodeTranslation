#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<char>> table(H, vector<char>(W));
    vector<bool> sheetV(H, false);
    vector<bool> sheetP(W, false);

    //入力部(確定)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> table.at(i).at(j);
        }
    }


    //圧縮部1(行圧縮工程)
    for (int i = 0; i < H; i++) {
        int count = 0;
        for (int j = 0; j < W; j++) {
            if (table.at(i).at(j) == '.') count++;
        }
        if (count == W) {
            
            sheetV.at(i) = true;
        }
    }

    //圧縮部2(列圧縮工程)
    for (int j = 0; j < W; j++) {
        int count = 0;
        for (int i = 0; i < H; i++) {
            if (table.at(i).at(j) == '.') count++;
        }
        if (count == H) {
            sheetP.at(j) = true;
        }
    }


    for (int i = 0; i < table.size(); i++) {
        if (sheetV.at(i) == true) continue;
        for (int j = 0; j < table.at(i).size(); j++) {
            if (sheetP.at(j) == true) continue;
            else {
                cout << table.at(i).at(j);
            }                
        }
        cout << endl;
    }


}