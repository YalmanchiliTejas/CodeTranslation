#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    for(int i = 0; i < H; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < W; j++) {
            grid.at(i).at(j) = line.at(j);
        }
    }
    for(int h = grid.size() - 1; h >= 0; h--) {
        bool all_white = true;
        for(char c : grid.at(h)) {
            if(c != '.') {
                all_white = false;
                break;
            }
        }
        if(all_white) {
            grid.erase(grid.begin() + h);
        }
    }
    for(int w = grid.at(0).size() - 1; w >= 0; w--) {
        bool all_white = true;
        for(int h = 0; h < grid.size(); h++) {
            if(grid.at(h).at(w) != '.') {
                all_white = false;
            }
        }
        if(all_white) {
            for(int h=0; h<grid.size(); h++){
                vector<char> line = grid.at(h);
                line.erase(line.begin() + w);
                grid.at(h) = line;
            }
        }
    }

    for(vector<char> line : grid) {
        for(char c : line) {
            cout << c;
        }
        cout << endl;
    }
}