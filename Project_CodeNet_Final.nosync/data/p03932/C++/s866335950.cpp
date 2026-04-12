#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int H, W;
vector<vector<int>> space;

int dp[300][300][599];

int move(int E869120_y, int square1001_y, int progress){
    if(dp[E869120_y][square1001_y][progress] != -1){
        return dp[E869120_y][square1001_y][progress];
    }else{
        vector<int> E869120_can_move_y;
        if(E869120_y != H - 1){
            E869120_can_move_y.push_back(E869120_y + 1);
        }
        if(progress - E869120_y != W - 1){
            E869120_can_move_y.push_back(E869120_y);
        }
        vector<int> square1001_can_move_y;
        if(square1001_y != H - 1){
            square1001_can_move_y.push_back(square1001_y + 1);
        }
        if(progress - square1001_y != W - 1){
            square1001_can_move_y.push_back(square1001_y);
        }
        int ans = 0;
        for(int i = 0; i < E869120_can_move_y.size(); i++){
            for(int j = 0; j < square1001_can_move_y.size(); j++){
                ans = max(ans, move(E869120_can_move_y[i], square1001_can_move_y[j], progress + 1));
            }
        }
        if(E869120_y == square1001_y){
            return dp[E869120_y][square1001_y][progress] = space[E869120_y][progress - E869120_y] + ans;
        }else{
            return dp[E869120_y][square1001_y][progress] = space[E869120_y][progress - E869120_y] + space[square1001_y][progress -  square1001_y] + ans;
        }
    }
}

int main(){
    cin >> H >> W;
    space.resize(H);
    for(int i = 0; i < H; i++){
        space[i].resize(W);
        for(int j = 0; j < W; j++){
            cin >> space[i][j];
        }
    }
    for(int i = 0; i < 300; i++){
        for(int j = 0; j < 300; j++){
            for(int k = 0; k < 599; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << move(0, 0, 0) << endl;
}

