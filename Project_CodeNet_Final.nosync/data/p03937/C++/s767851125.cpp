#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    char A[8][8];
    int cnt = 0;
    for(int i=0; i<H; ++i) {
        for(int j=0; j<W; ++j) {
            cin >> A[i][j];
            if(A[i][j] == '#') ++cnt;
        }
    }

    if(cnt == H + W - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}