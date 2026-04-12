#include <bits/stdc++.h>
using namespace std;


// 指定した行が白色のみか調べる関数
bool is_white_row(vector<vector<char>> &grid, int y) {
    bool ret = true;

    for(int x=0; x<grid[y].size(); x++) {
        if (grid[y][x] == '#') {
            ret = false;
            break;
        }
    }

    return ret;
}


// 指定した列が白色のみか調べる関数
bool is_white_col(vector<vector<char>> &grid, int x) {
    bool ret = true;

    for(int y=0; y<grid.size(); y++) {
        if (grid[y][x] == '#') {
            ret = false;
            break;
        }
    }

    return ret;
}


// グリッドを詰める関数（'x'で置き換える）
// n : 詰める行番号もしくは列番号
// option : 列を詰めるか行を詰めるか（0 : 行, 1 : 列）
void compress_grid(vector<vector<char>> &grid, int n, int option) {

    // 行を詰めるとき
    if (option == 0) {
        for(int x=0; x<grid[n].size(); x++) {
            grid[n][x] = 'x';
        }
    }

    // 列を詰めるとき
    else if (option == 1) {
        for(int y=0; y<grid.size(); y++) {
            grid[y][n] = 'x';
        }
    }

}


int main() {
    int H, W;
    cin >> H >> W;
    
    // グリッド
    // 白 : '.' / 黒 : '#' / 詰めたマス : 'x'
    vector<vector<char>> grid(H, vector<char>(W));

    // グリッドの初期状態を読み込む
    for(int i=0; i<H; i++) {
        string line;
        cin >> line;
        for(int j=0; j<line.size(); j++) {
            grid[i][j] = line.at(j);
        }
    }

    // 行方向で圧縮
    for(int y=0; y<H; y++) {
        if (is_white_row(grid, y)) {
            compress_grid(grid, y, 0);
        }
    }

    // 列方向で圧縮
    for(int x=0; x<W; x++) {
        if (is_white_col(grid, x)) {
            compress_grid(grid, x, 1);
        }
    }

    // 結果を表示
    int cout_count;
    for(int y=0; y<grid.size(); y++) {
        cout_count = 0;
        for(int x=0; x<grid[y].size(); x++) {
            if (grid[y][x] != 'x') {
                cout << grid[y][x];
                cout_count++;
            }
        }
        if (cout_count != 0) {
            cout << endl;
        }
    }
}