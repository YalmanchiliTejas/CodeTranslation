#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char mark;
            cin >> mark;
            table.at(i).at(j) = mark;
        }
    }
    
    for(int i = 0; i < H; i++){
        ll countW = 0;
        for(int j = 0; j < W; j++){
            if(table.at(i).at(j) == '.'){
                countW++;
            }
        }
        if(countW == W){
            for(int k = 0; k < W; k++) table.at(i).at(k) = '!';
        }
    }
    
    for(int i = 0; i < W; i++){
        ll countH = 0;
        for(int j = 0; j < H; j++){
            if(table.at(j).at(i) == '.' || table.at(j).at(i) == '!'){
                countH++;
            }
        }
        if(countH == H){
            for(int k = 0; k < H; k++) table.at(k).at(i) = '!';
        }
    }

    for(int i = 0; i < H; i++){
        bool returnFlag = false;
        for( int j = 0; j < W; j++){
            if(table.at(i).at(j) != '!'){
                cout << table.at(i).at(j);
                returnFlag = true;
            }
        }
        if(returnFlag == true) cout << endl;
    }
}