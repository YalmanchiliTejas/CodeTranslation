#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    vector<vector<char>> a(H,vector<char>(W));
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            cin >> a[i][j];
        }
    }

    vector<bool> row(H,false);
    vector<bool> col(W,false);
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            if(a[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for(int i=0;i<H;i++) {
        if(row[i]) {
            for(int j=0;j<W;j++) {
                if(col[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}