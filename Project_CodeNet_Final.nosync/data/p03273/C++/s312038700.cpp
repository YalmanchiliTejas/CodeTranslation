#include<bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>>grid(H,vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> grid.at(i).at(j);
        }
    }
    for(int i = 0; i < H; i++){
        bool isspace = true;
        for(int j = 0; j < W; j++){
            if(grid.at(i).at(j) == '#'){
                isspace = false;
                break;
            }
        }
        if(isspace){
            grid.erase(grid.begin() + i);
            H--;
            i--;
        }
    }

    for(int i = 0; i < W; i++){
        bool isspace = true;
        for(int j = 0; j < H; j++){
            if(grid.at(j).at(i) == '#'){
                isspace = false;
                break;
            }
        }
        if(isspace){
            for(int j = 0; j < H; j++){
                grid.at(j).erase(grid.at(j).begin() + i);
            }
            W--;
            i--;
        }
            
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << grid.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}