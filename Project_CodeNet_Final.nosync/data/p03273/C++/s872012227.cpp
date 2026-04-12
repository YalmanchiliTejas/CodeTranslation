#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<char>> g(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < H; i++){
        bool flag1 = false;

        for(int j = 0; j < W; j++){
            if (g[i][j] == '#') flag1 = true;
        }
        if(flag1){
            for(int k = 0; k < W; k++){
                bool flag2 = false;
                for(int l = 0; l < H; l++){
                    if(g[l][k] == '#') flag2 = true;
                }
                if(flag2) cout << g[i][k];
            }
            cout << endl;
        }
    }
}