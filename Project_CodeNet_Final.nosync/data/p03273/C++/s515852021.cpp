#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG



int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<char>> map (H, vector<char>(W));
    for (int i=0;i<H;i++) {
        for (int j=0;j<W;j++) {
            cin >> map.at(i).at(j);
        }
    }

    vector<bool> black_in_row(H,false);
    vector<bool> black_in_column(W,false);

    for (int i=0;i<H;i++) {
        for (int j=0;j<W;j++) {
            if (map.at(i).at(j) == '#') {
                black_in_row.at(i) = true;
                black_in_column.at(j) = true;
            }
        }
    }

    for (int i=0;i<H;i++) {
        for (int j=0;j<W;j++) {
            if (black_in_row.at(i) && black_in_column.at(j)) {
                cout << map.at(i).at(j);
            }
        }
        if (black_in_row.at(i)){
            cout << endl;
        }
    }


}