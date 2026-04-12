#include<iostream>
using namespace std;
int main() {
    int h, w;
    cin >> h >> w;
    char a[101][101];
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i][j] == '.') {
                cnt++;
            }
        }
        if (cnt == w) {
            for (int i2 = i; i2 <= h; i2++) {
                for (int j = 1; j <= w; j++) {
                    a[i2][j] = a[i2 + 1][j];
                }
                if (i2 == h) {
                    h--;
                }
            }
            i--;
        }
        cnt = 0;
    }
    /*
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }*/
    
    
    
    
    for (int j = 1; j <= w; j++) {
        for (int i = 1; i <= h; i++) {
            if (a[i][j] == '.' || a[i][j] == '+') {
                cnt++;
            }
        }
        if (cnt == h) {
            for (int j2 = j; j2 <= w; j2++) {
                for (int i = 1; i <= h; i++) {
                    a[i][j2] = a[i][j2 + 1];
                }
                if (j2 == w) {
                    w--;
                }
            }
            j--;
        }
        cnt = 0;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

