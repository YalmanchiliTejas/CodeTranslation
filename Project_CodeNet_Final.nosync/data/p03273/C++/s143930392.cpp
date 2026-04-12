#include<iostream>
#define MAX_H 101
#define MAX_W 101
using namespace std;

char grid[MAX_H][MAX_W];
bool tate[MAX_W], yoko[MAX_H];

int main() {
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> grid[i][j];
    }
    for (int i = 0; i < H; i++) yoko[i] = false;
    for (int i = 0; i < W; i++) tate[i] = false;
    for (int i = 0; i < H; i++) {
        bool flag = true;
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') flag = false;
        }
        if (flag) yoko[i] = true;
    }
    for (int i = 0; i < W; i++) {
        bool flag = true;
        for (int j = 0; j < H; j++) {
            if (grid[j][i] == '#') flag = false;
        }
        if (flag) tate[i] = true;
    }
    for (int i = 0; i < H; i++) {
        if (yoko[i]) continue;
        for (int j = 0; j < W; j++) {
            if (tate[j]) continue;
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}