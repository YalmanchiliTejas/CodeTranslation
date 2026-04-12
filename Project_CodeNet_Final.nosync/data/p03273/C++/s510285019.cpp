#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int h, w;
    cin >> h >> w;
    char grid[h][w];
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> grid[i][j];
        }
    }
    
    int a[h], b[w];
    int x;
    for (int i=0; i<h; i++) {
        x = 0;
        for (int j=0; j<w; j++) {
            if (grid[i][j] == '.') x++;
        }
        if (x == w) a[i] = 0;
        else a[i] = 1;
    }
    
    for (int i=0; i<w; i++) {
        x = 0;
        for (int j=0; j<h; j++) {
            if (grid[j][i] == '.') x++;
        }
        if (x == h) b[i] = 0;
        else b[i] = 1;
    }
    
    for (int i=0; i<h; i++) {
        if (a[i]) {
            for (int j=0; j<w; j++) {
                if (b[j]) {
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}