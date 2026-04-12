#include<bits/stdc++.h>
using namespace std;

int main() {
    int h;  cin >> h;
    int w;  cin >> w;

    char tile[h][w];
    for (int i = 0; i < h; i++) {
        for(int j=0;j<w;j++){
            cin >> tile[i][j];
        }
    }

    bool row[h]={false};
    bool col[w]={false};
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (tile[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        if (row[i]) {
            for (int j = 0; j < w; j++) {
                if (col[j]) {
                    cout << tile[i][j];
                }
            }
            cout << endl;
        }
    }
}
