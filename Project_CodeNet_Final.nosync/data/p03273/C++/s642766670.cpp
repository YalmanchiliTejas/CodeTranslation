#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    
    for (int i=0; i<H; i++) {
        vector<char> row(W);
        for (int j=0; j<W; j++) {
            cin >> row.at(j);
        }
        grid.at(i) = row;
    }
    
    vector<bool> row(H), column(W);
    
    for (int i=0; i<H; i++) {
        bool flag = true;
        for (int j=0; j<W; j++) {
            if (grid.at(i).at(j) == '#') flag = false;
        }
        row.at(i) = flag;
    }
    
    
    for (int i=0; i<W; i++) {
        bool flag = true;
        for (int j=0; j<H; j++) {
            if (grid.at(j).at(i) == '#') flag = false;
        }
        column.at(i) = flag;
    }
    
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (row.at(i) || column.at(j)) continue;
            cout << grid.at(i).at(j);
        }
    if (!row.at(i)) cout << endl;
    }
}
