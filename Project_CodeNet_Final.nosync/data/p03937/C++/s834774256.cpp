#include <iostream>
#define MAX_H 8
#define MAX_W 8
using namespace std;

int H, W;
char A[MAX_H][MAX_W];

void bfs(int i, int j){
    A[i][j] = '.';
    if(i == W - 1 && j == H - 1) return;

    int rx = i + 1, ry = j, dx = i, dy = j + 1;
    if(rx < W && A[rx][ry] == '#') bfs(rx, ry);
    else if(dy < H && A[dx][dy] == '#') bfs(dx, dy);
}


int main(){
    cin >> H >> W;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            cin >> A[j][i];
        }
    }
    bfs(0, 0);
    
    bool flg = true;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j) {
            if(A[j][i] != '.') flg = false;
        }
    }

    cout << (flg ? "Possible" : "Impossible") << endl;
    return 0;
}

