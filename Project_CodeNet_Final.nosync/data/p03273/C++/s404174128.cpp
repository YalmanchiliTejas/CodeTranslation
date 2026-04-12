#include <bits/stdc++.h>
using namespace std;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> a(H, vector<char>(W));

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a.at(i).at(j);
        }
    }

    vector<char> temp(H), white(W, '.');
    for(int i = 0; i < H; i++){
        if(a.at(i) == white){
            for(int j = i; j < H-1; j++){
                swap(a.at(j), a.at(j+1));
            }
            i--;
            H--;
        }
    }

    int check;
    for(int i = 0; i < W; i++){
        check = 0;
        for(int j = 0; j < H; j++){
            if(a.at(j).at(i) == '.') check++;
        }
        if(check == H){
            for(int j = 0; j < H; j++){
                for(int k = i; k < W-1; k++){
                    swap(a.at(j).at(k), a.at(j).at(k+1));
                }
            }
            i--;
            W--;
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
}
