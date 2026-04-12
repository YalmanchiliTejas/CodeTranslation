#include<iostream>
#include <vector>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grid = vector<vector<char>>(H, vector<char>(W, 0));
    vector<bool> isEmptyRow = vector<bool>(H, true);
    vector<bool> isEmptyCol = vector<bool>(W, true);
    int i, j;
    for(i = 0; i < H; ++i) {
        for(j = 0; j < W; ++j) {
            cin >> grid[i][j];
            if( grid[i][j] == '#' ) {
                isEmptyRow[i] = false;
                isEmptyCol[j] = false;
            }
        }
    }

    for(i = 0; i < H; ++i) {
        if( isEmptyRow[i] ) continue;
        for(j = 0; j < W; ++j) {
            if( isEmptyCol[j] ) continue;
            cout << grid[i][j];
        }
        printf("\n");
    }

    return 0;
}