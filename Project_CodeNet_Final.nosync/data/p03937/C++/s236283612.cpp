#include <bits/stdc++.h>
using namespace std;

int H, W;
char A[8][8];
// 右または下への移動
int dy[2] = {0, 1}, dx[2] = {1, 0};
bool flag = 0, check;

bool dfs(int y, int x, char reached[8][8]){
    // cout << "x = " << x << ", y = " << y << endl;  
    // 到達マスを'#'にする
    reached[y][x] = '#';
    check = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(A[i][j] != reached[i][j]){
                check = 1;
            }
        }
    }
    // 一致しないマスが存在しなかった
    if(check == 0)
        flag = 1;


    /* 
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << reached[i][j];  
        }
        cout << endl;
    }
    cout << endl;
    */

    // 右または下への移動
    for(int i=0;i<2;i++){
        if(A[y + dy[i]][x + dx[i]] == '#' && x + dx[i] < W && y + dy[i] < H)
            dfs(y + dy[i], x + dx[i], reached);
    }
    reached[y][x] = '.';
}
 
int main(){
    cin >> H >> W;
    char reached[8][8] = {};
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> A[i][j];
            // 初期状態：全てのマスが未到達
            reached[i][j] = '.';
        }
    }
    // 左上隅のマスからスタート
    dfs(0, 0, reached);
    if(flag == 1)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    
    return 0;
}