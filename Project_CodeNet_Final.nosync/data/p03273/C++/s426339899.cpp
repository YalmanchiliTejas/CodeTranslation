#include <bits/stdc++.h>
using namespace std;

int main(void){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H+1, vector<char>(W+1));
    
    for (int i = 1; i < H+1; i++) {
        for (int j = 1; j < W+1; j++) {
            cin >> a.at(i).at(j);
        }
    }
    
    // 行の確認
    for (int i = 1; i < H+1; i++) {
        bool is_all_white = false;
        int white_counter = 0;
        for (int j = 1; j < W + 1; j++) {
            if (a.at(i).at(j) == '.') {
                white_counter++;
            }
        }
        if (white_counter == W) {
            is_all_white = true;
        }
        if (is_all_white) {
            a.at(i).at(0) = '*';
        }
    }
    
    // 列の確認
    for (int i = 1; i < W + 1; i++) {
        bool is_all_white = false;
        int white_counter = 0;
        for (int j = 1; j < H + 1; j++) {
            if (a.at(j).at(i) == '.') {
                white_counter++;
            }
        }
        if (white_counter == H) {
            is_all_white = true;
        }
        if (is_all_white) {
            a.at(0).at(i) = '*';
        }
    }
    
    for (int i = 1; i < H + 1; i++) {
        // cout << a.at(0).at(i) << endl;
        for (int j = 1; j < W + 1; j++) {
            if (a.at(0).at(j) == '*' || a.at(i).at(0) == '*') {
                continue;
            }
            cout << a.at(i).at(j);
            
            bool bl = true;
            for (int k = j + 1; k < W + 1; k++) {
                if (a.at(0).at(k) != '*')
                    bl = false;
            }
            if (bl) {
                cout << endl;
            }
        }
    }
}