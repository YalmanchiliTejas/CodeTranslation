#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll H, W, cnt = 0;
    cin >> H >> W;
    char board[H][W];
    memset(board, '.',sizeof(board));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> board[i][j];
            if(board[i][j] == '#') cnt++;
        }
    }
    bool flag = true;
    if(cnt != H + W - 1){
        flag = false;
    }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(board[i][j] == '.') continue;
            if(i + 1 != H && board[i + 1][j] == '#'){

            }else if(j + 1 != W && board[i][j + 1] == '#'){

            }else if(i + 1 == H && j + 1 == W){
            }else{
                flag = false;
            }
        }
    }

    if(flag){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }

    return 0;
}   
