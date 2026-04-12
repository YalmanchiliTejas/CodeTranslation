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
            for (int j = 1; j <= w; j++) {
                a[i][j] = '+';
            }
        }
        cnt = 0;
    }
    for (int j = 1; j <= w; j++) {
        for (int i = 1; i <= h; i++) {
            if (a[i][j] == '.' || a[i][j] == '+') {
                cnt++;
            }
        }
        if (cnt == h) {
            for (int i = 1; i <= h; i++) {
                a[i][j] = '+';
            }
        }
        cnt = 0;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i][j] != '+') {
                cout << a[i][j];
            }
        }
        cout << endl;
    }
}

