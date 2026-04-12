#include<bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> V(H+1, vector<char>(W+1));
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            cin >> V[i][j];
        }
    }
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            if(V[i][j] == '#') break;
            else if(j == W){
                for(int k = 1; k <= W; ++k) V[i][k] = '@';
            }
        }
    }
    for(int j = 1; j <= W; ++j){
        for(int i = 1; i <= H; ++i){
            if(V[i][j] == '#') break;
            else if(i == H){
                for(int k = 1; k <= H; ++k) V[k][j] = '@';
            }
        }
    }
    for(int i = 1; i <= H; ++i){
        int flag = 0;
        for(int j = 1; j <= W; ++j){
            if(V[i][j] != '@'){
                flag = 1;
                cout << V[i][j];
            }
        }
        if(flag) cout << endl;
    }
    return 0;
}