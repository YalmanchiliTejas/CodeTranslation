#include <bits/stdc++.h>
using namespace std;
int main(void){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> a(H,vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a[i][j];
        }
    }
    
    bool flag1 = true;
    bool flag2 = true;
    
        for(int i = 0; i < H; i++){
            flag1 = true;
            for(int j = 0; j < W; j++){
               if(a[i][j] == '#') flag1 = false;
            }
            if(flag1 == true){
                for(int j = 0; j < W; j++){
                    a[i][j] = 'a';
                }
            }
        }
        
        for(int j = 0; j < W; j++){
               flag2 = true;
            for(int i = 0; i < H; i++){
               if(a[i][j] == '#') flag2 = false;
            }
            if(flag2 == true){
                for(int i = 0; i < H; i++){
                    a[i][j] = 'a';
                }
            }
        }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            flag1 = true;
            
            for(int j = 0; j < W; j++){
               if(a[i][j] == '#' || a[i][j] == '.') flag1 = false;
            }
            
            if(a[i][j] != 'a') cout << a[i][j];
            if(j == W-1 && flag1 == false) cout << endl;
        }
    }
}
