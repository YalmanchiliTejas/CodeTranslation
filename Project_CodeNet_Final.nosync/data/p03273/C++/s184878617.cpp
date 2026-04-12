#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    string data[H];
    for (int i = 0; i < H; i++) {
        cin >> data[i];
    }
    
    vector<int> row(H, 0);
    vector<int> col(W, 0);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (data[i][j] == '#') {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        if (row[i] == 1){
            for (int j = 0; j < W; j++) {
                if (col[j] == 1){
                    cout << data[i][j];
                }
            }
            cout << endl; // cout << '\n'; のほうが速い
        }
    }
}
