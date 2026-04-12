#include <bits/stdc++.h> 
using namespace std;
 
int main(){
    int H, W, count;
    cin >> H >> W;
    vector<vector<char>> vec(H, vector<char>(W,NULL)); //マス情報
    vector<bool> vech(H,false); //縦
    vector<bool> vecw(W,false); //横
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> vec[i][j];
        }
    }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(vec[i][j]=='#'){
                vecw[i]=true;
                vech[j]=true;
            }
        }
    }
    
    /*
    for(int j = 0; j < W; j++){
        for(int i = 0; i < H; i++){
            if(vec[i][j]=='#'){
                vech[j]=1;
            }
        }
    }
    */
    
    for(int i = 0; i < H; i++){
        if(vecw[i]==true){
          for(int j = 0; j < W; j++){
                if(vech[j] == true){
                    cout << vec[i][j];
                }
            }
            cout << endl;
        }
    }
    
}