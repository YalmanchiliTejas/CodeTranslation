#include<bits/stdc++.h>
using namespace std;

int main(void){

    int H,W; cin>>H>>W;

    vector<string> mas(H);
    for (int i = 0; i < H; ++i) {
        cin>>mas[i];
    }

    vector<bool> row(H, false), column(W, false);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if(mas[i][j] == '#'){
                row[i] = true;
                column[j] = true;
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        if(row[i]) {
            for (int j = 0; j < W; ++j) {
                if (column[j] == true) cout << mas[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}