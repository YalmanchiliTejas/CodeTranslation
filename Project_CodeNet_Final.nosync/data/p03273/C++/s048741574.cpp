#include <bits/stdc++.h>
using namespace std;
// 写経
int main() {
    int x, y;
    cin >> x >> y;
    string board[110];
    bool goodx[110]={false}, goody[110]={false};
    for(int i=0; i<x; i++) {
        cin >> board[i];
    }
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            if(board[i][j]=='#') {
                goodx[i]=true;
                goody[j]=true;
            }
        }
    }

    for(int i=0; i<x; i++) {
        if(goodx[i]) {
            for(int j=0; j<y; j++) {
                if(goody[j]) {
                    cout << board[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}