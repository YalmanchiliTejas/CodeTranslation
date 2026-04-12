#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    char A[H][W];
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            cin >> A[i][j];
        }
    }
    vector <bool> row(H, false);
    vector <bool> col(W, false);
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if (A[i][j]=='#'){
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for (int i=0; i<H; i++){
        if (row[i]){
            for (int j=0; j<W; j++){
                if (col[j]){
                    cout << A[i][j];
                }
            }
            cout << endl;
        }
    }
}