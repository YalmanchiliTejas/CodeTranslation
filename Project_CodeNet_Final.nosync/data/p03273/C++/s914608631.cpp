#include <iostream>

using namespace std;
int main() {
    int h, w; cin >> h >> w;
    char a[h+1][w+1];
    for (int i = 1; i <= h; i++) {
        for (int k = 1; k <= w; k++) {
            cin >> a[i][k];
        }
    }
    for (int i = 1; i <= h; i++) {
        bool judge = true;
        for (int k = 1; k <= w; k++) {
            if (a[i][k] == '#') {
                judge = false;
                break;
            }
        }
        if (judge) {
            for (int j = 1; j <= w; j++) {
                a[i][j] = ' ';
            }
        }
    }
    
    for (int i = 1; i <= w; i++) {
        bool judge = true;
        for (int k = 1; k <= h; k++) {
            if (a[k][i] == '#') {
                judge = false;
                break;
            }
        }
        if (judge) {
            for (int j = 1; j <= h; j++) {
                a[j][i] = ' ';
            }
        }
    }
    for (int i = 1; i <= h; i++) {
        bool draw = false;
        for (int k = 1; k <= w; k++) {
            if (a[i][k] != ' ') {
                cout << a[i][k];
                draw = true;
            }
        }
        if (draw) cout << "\n";
    }
    return 0;
}
