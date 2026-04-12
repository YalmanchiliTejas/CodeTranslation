#include<iostream>
#define MAX_NUM 8
using namespace std;

int H, W;
char grid[MAX_NUM][MAX_NUM];

void dfs(int h, int w) {
    grid[h][w] = '.';
    if (w + 1 < W && grid[h][w + 1] == '#') dfs(h, w + 1);
    else if (h + 1 < H && grid[h + 1][w] == '#') dfs(h + 1, w);
    return;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> grid[i][j];
    }
    dfs(0, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}