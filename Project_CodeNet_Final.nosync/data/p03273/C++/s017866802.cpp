#include <bits/stdc++.h>
using namespace std;
int main(void){
    int H, W;
    cin >> H >> W;
    
    vector<vector<char>> mass(H, vector<char>(W));
    
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> mass.at(i).at(j);
        }
    }


    for (int j = 0; j < W; j++){
        for (int i = 0; i < H; i++){
            if (mass.at(i).at(j) == '#'){
                break;
            }
            if ((i == H - 1) && (mass.at(i).at(j) == '.')){
                for (int k = 0; k < H; k++){
                        mass.at(k).at(j) = '0';
                }
                
            }
        }
    }
    
        
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (mass.at(i).at(j) == '#'){
                break;
            }
            if ((j == W - 1) && (mass.at(i).at(j) == '.' || mass.at(i).at(j) == '0')){
                for (int k = 0; k < W; k++){
                    mass.at(i).at(k) = '0';
                }
                mass.at(i).at(W - 1) = '1';
            }
        }
    }
    
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (!((mass.at(i).at(j) == '0') || (mass.at(i).at(j) == '1'))){
                cout << mass.at(i).at(j);
            }
            if ((j == W - 1) && (!(mass.at(i).at(j) == '1')))
                cout << endl;
        }
    }
}