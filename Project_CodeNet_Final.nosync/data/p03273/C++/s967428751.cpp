#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> data(H, vector<char>(W));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> data.at(i).at(j);
        }
    }
    int countW, countH;

    for(int i = 0; i < H; i++) {
        countW = 0;
        for(int j = 0; j < W; j++) {
            if(data.at(i).at(j) == '.'){
                countW++;
            }
            if(countW == W){
                for(int k = 0; k < W; k++) {
                    data.at(i).at(k) = 'D';
                }
            }
        }
    }

    for(int j = 0; j < W; j++) {
        countH = 0;
        for(int i = 0; i < H; i++) {
            if(data.at(i).at(j) == '.' || data.at(i).at(j) == 'D'){
                countH++;
            }
            if(countH == H){
                for(int k = 0; k < H; k++) {
                    data.at(k).at(j) = 'D';
                }
            }
        }
    }
    
    int X = 0;

    for (int i = 0; i < H; i++) {
        if (X > 0) {
            cout << endl;
        }
        X = 0;
        for (int j = 0; j < W; j++) {
            if (data.at(i).at(j) == 'D') {
                continue;
            }
            else {
                cout << data.at(i).at(j);
                X++;
            }
        }
    }

}
