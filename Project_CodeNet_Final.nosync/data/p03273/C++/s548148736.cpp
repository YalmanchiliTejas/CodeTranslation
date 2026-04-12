#include <bits/stdc++.h>
using namespace std;
int H, W;
char route[110][110];
int main() {
    cin >> H >> W;
    vector<int> checkerH(H);
    vector<int> checkerW(W);

    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> route[i][j];
            if(route[i][j] == '#') {
                checkerH.at(i) = 1;
                checkerW.at(j) = 1;
            }
        }
    }

    for(int i = 0; i < H; ++i) {
        if(checkerH.at(i) == 1) {
            for(int j = 0; j < W; ++j) {
                if(checkerW.at(j) == 1) {
                    cout << route[i][j];
                }
            }
            cout << endl;
        }
    }
}
