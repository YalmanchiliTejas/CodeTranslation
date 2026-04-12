#include <bits/stdc++.h>
using namespace std;


int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A.at(i).at(j);
        }
    }
    
    for (int i = 0; i < H; i++) {
        bool B = false;
        for (int j = 0; j < W; j++) {
            if (A.at(i).at(j) == '#') {
                B = true;
            }
        }
        if (B == false)
        for (int j = 0; j < W; j++) {
            A.at(i).at(j) = 'x';
        }
    }
    
     for (int i = 0; i < W; i++) {
        bool B = false;
        for (int j = 0; j < H; j++) {
            if (A.at(j).at(i) == '#') {
                B = true;
            }
        }
        if (B == false)
        for (int j = 0; j < H; j++) {
            A.at(j).at(i) = 'x';
        }
    }
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A.at(i).at(j) != 'x') {
                cout << A.at(i).at(j);
            }
        }
        bool C = false;
        for (int j = 0; j < W; j++) {
            if (A.at(i).at(j) != 'x') {
                C = true;
            }
        }
        if (C)
        cout << endl;
    }
}