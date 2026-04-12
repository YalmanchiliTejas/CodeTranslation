#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a.at(i).at(j);
        }
    }
    int row = H;
    int col = W;
    vector<int> memorow;
    vector<int> memocol;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(j == W - 1 && a.at(i).at(j) == '.'){
                memorow.push_back(i);
                row--;
            }
            if(a.at(i).at(j) == '#'){
                break;
            }
        }
    }
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            if(j == H - 1 && a.at(j).at(i) == '.'){
                memocol.push_back(i);
                col--;
            }
            if(a.at(j).at(i) == '#'){
                break;
            }
        }
    }
    int MR = memorow.size();
    int MC = memocol.size();
    vector<vector<char>> revised(row, vector<char>(col));
    int x = 0;
    int y = 0;
    for(int i = 0; i < H; i++){
        bool flag1 = false;
        for(int k1 = 0; k1 < MR; k1++){
            if(i == memorow.at(k1)){
                flag1 = true;
                break;
            }
        }
        if(flag1){
            continue;
        }
        y = 0;
        for(int j = 0; j < W; j++){
            bool flag2 = false;
            for(int k2 = 0; k2 < MC; k2++){
                if(j == memocol.at(k2)){
                    flag2 = true;
                    break;
                }
            }
            if(flag2){
                continue;
            }
            revised.at(x).at(y) = a.at(i).at(j);
            cout << revised.at(x).at(y);
            y++;
        }
        x++;
        cout << endl;
    }
}