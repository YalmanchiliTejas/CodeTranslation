#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a.at(i).at(j);
        }
    }
    vector<int> row;
    vector<int> line;
    for(int i = 0; i < H; i++){
        bool judge = true;
        for(int j = 0; j < W; j++){
            if(a.at(i).at(j) == '#'){
                judge = false;
                break;
            }
        }
        if(judge){
            row.push_back(i);
        }
    }
    for(int j = 0; j < W; j++){
        bool judge = true;
        for(int i = 0; i < H; i++){
            if(a.at(i).at(j) == '#'){
                judge = false;
                break;
            }
        }
        if(judge == true){
            line.push_back(j);
        }
    }
    for(int r = 0; r < row.size(); r++){
        for(int w = 0; w < W; w++){    
            a.at(row.at(r)).at(w) = '-';
        }
    }
    for(int l = 0; l < line.size(); l++){
        for(int h = 0; h < H; h++){
            a.at(h).at(line.at(l)) = '-';
        }
    }
    for(int i = 0; i< H; i++){
        int count = 0;
        for(char j : a.at(i)){
            if(j != '-'){
                cout << j;
            }
            else{
                count++;
            }
        }
        if(count != W){
            cout << endl;
        }
    }
}