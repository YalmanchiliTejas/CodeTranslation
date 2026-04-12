#include<bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    vector<vector<char>> ans(100, vector<char>(100, ' '));
    vector<bool> memo(100, false);
    vector<bool> memo2(100, false);
    for(int i = 0;i < H;i++){
        for(int k = 0;k < W;k++){
            cin >> a.at(i).at(k);
        }
    }
    for(int i = 0;i < H;i++){
        for(int k = 0;k < W;k++){
            if((a.at(i).at(k)) == '.'){
                if(k == W-1){
                    memo.at(i) = true;
                }
            }
            else{
                break;
            }
        }
    }
     for(int i = 0;i < W;i++){
        for(int k = 0;k < H;k++){
            if((a.at(k).at(i)) == '.'){
                if(k == H-1){
                    memo2.at(i) = true;
                }
            }
            else{
                break;
            }
        }
    }
    for(int i = 0;i < H;i++){
        if(memo.at(i)){
            continue;
        }
        for(int k = 0;k < W;k++){
            if(memo2.at(k)){
                if(k == W-1) cout << endl;
                continue;
            }
            else{
                cout << a.at(i).at(k);
                if(k == W-1) cout << endl;
            }
        }
    }
}