#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    
    // 0行0列はラベル
    // o なら白いマスのみの[行または列]
    vector<vector<char>> table(H+1, vector<char>(W + 1, '-'));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> table.at(i).at(j);
        }
    }
    
    // 行のチェック
    for (int i = 1; i <= H; i++) {
        int count = 0;
        for (int j = 1; j <= W; j++) {
            if (table.at(i).at(j) == '.') {
                count++;
            }
        }
        if (count == W) {
            table.at(i).at(0) = 'o';
        }
    }
    
    
    // 列のチェック
    int compressed_W = W;
    for (int i = 1; i <= W; i++) {
        int count = 0;
        for (int j = 1; j <= H; j++) {
            if (table.at(j).at(i) == '.') {
                count++;
            }
        }
        if (count == H) {
            table.at(0).at(i) = 'o';
            compressed_W--;
        }
    }
    
    table.at(0).at(0) = 'o';
    
    
    for (int i = 1; i <= H; i++) {
        
        if(table.at(i).at(0) == 'o') {
            continue;
        }
        int count = 0;
        for (int j = 1; j <= W; j++) {
            if (table.at(0).at(j) != 'o') {
                count++;
                cout  << table.at(i).at(j);
                if(count == compressed_W) {
                    cout << endl;
                }
            }
        }
        
    }
}