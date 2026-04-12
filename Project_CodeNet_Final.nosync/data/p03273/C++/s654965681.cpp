//
// Created by moono on 2018/10/27.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;


int main() {
    int H, W;
    cin >> H >> W;

    char c;
    char table[H][W];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> c;
            table[i][j] = c;
        }
    }




    //
    set<int> compress_row, compress_col;


    //
    for (int i = 0; i < H; ++i) {
        bool can_compress = true;
        for (int j = 0; j < W; ++j) {
            if(table[i][j] == '#') {
                can_compress = false;
                break;
            }
        }
        if(can_compress) compress_row.insert(i);
    }


    //
    for (int j = 0; j < W; ++j) {
        bool can_compress = true;
        for (int i = 0; i < H; ++i) {
            if(table[i][j] == '#') {
                can_compress = false;
                break;
            }
        }
        if(can_compress) compress_col.insert(j);
    }


//    for (int i = 0; i < H; ++i) {
//        for (int j = 0; j < W; ++j) {
//            cout << table[i][j];
//        }
//        cout << endl;
//    }
//    cout << compress_row.size() << endl;
//    cout << compress_col.size() << endl;


    // 
    for (int i = 0; i < H; ++i) {
        if(compress_row.find(i) != compress_row.end())
            continue;

        for (int j = 0; j < W; ++j) {
            if(compress_col.find(j) != compress_col.end()){
                continue;
            }
            cout << table[i][j];
        }
        cout << endl;
    }




    return 0;
}