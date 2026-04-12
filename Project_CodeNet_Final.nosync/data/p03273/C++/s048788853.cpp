#include <iostream>
using namespace std;
int main(){
    int h,w; cin >> h >> w;
    char a[h+1][w+1];
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') break;
            if (j == w - 1) {
                for (int k = i; k < h - 1; k++) {
                    for (int l = 0; l < w; l++) {
                        a[k][l] = a[k+1][l];
                    }
                }
                h--;
                i--;
            }
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (a[j][i] == '#') break;
            if (j == h - 1) {
                for (int k = i; k < w - 1; k++) {
                    for (int l = 0; l < h; l++) {
                        a[l][k] = a[l][k+1];
                    }
                }
                w--;
                i--;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j];
            if (j == w - 1) cout << endl;
        }
    }
}