#include <bits/stdc++.h>
using namespace std;
const int lim = 100;

string solve(string hs){
    int from_y, from_x, to_y, to_x;
    cin >> from_y >> from_x >> to_y >> to_x;
    // init
    char board[lim][lim];
    for(int i=0; i<lim; i++){
        for(int j=0; j<lim; j++) board[i][j] = ' ';
    }

    //盤面を復元
    int y = 0;
    int x = 0;
    for(char c: hs){
        if(c == 'b'){
            board[y][x] = 'b';
            x++;
        } 
        else if(c == '/'){
            y++;
            x = 0;
        }
        else {
            int num = (c - '0');
            for(int i=0; i<num; i++){
                board[y][x] = '.';
                x++;
            }
        }
    }

    //ボールを移動
    board[to_y-1][to_x-1] = 'b';
    board[from_y-1][from_x-1] = '.';
    

    //圧縮
    string ret = "";
    for(int i=0; i<=y; i++){
        for(int j=0; j<x; j++){
            if(board[i][j] == '.'){
                int cnt = 0;
                int nx = j;
                while(board[i][nx] == '.'){
                    cnt++;
                    nx++;
                }
                ret += to_string(cnt);
                j = nx-1;
            }
            else if(board[i][j] == 'b') ret += "b";
        }
        if(i != y) ret += "/";
    }
    return ret;
}

int main(){
    while(true){
        string hs;
        cin >> hs;
        if(hs == "#") return 0;
        cout << solve(hs) << endl;
    }
    
}
