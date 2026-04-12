#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int H,W;
    cin >> H>>W;
    string board[110];
    for(int i = 0;i < H;i++) cin >> board[i];
    vector<int> X(110,0);
    vector<int> Y(110,0);
    for(int i = 0 ;i < H;i++){
        for(int j = 0;j < W;j++){
            if(board[i][j] == '#'){
                X[j] = 1;
                Y[i] = 1; 
            }
        }
    }
    for(int i = 0;i < H;i++){
        if(Y[i]){
            for(int j = 0;j < W;j++){
                if(X[j]){
                    cout << board[i][j];
                }
            }
            cout << endl;
        }
    }
}