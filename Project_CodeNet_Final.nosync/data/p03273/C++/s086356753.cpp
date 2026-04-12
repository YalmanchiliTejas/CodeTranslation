#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        bool r = true;
        for(int j = 0; j < w; j++) {
            if (a[i][j] == '#') {
                r = false;
                break;
            }
        }
        if (r) {
            for(int j = 0; j < w; j++) {
                a[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < w; i++) {
        bool r = true;
        for(int j = 0; j < h; j++) {
            if (a[j][i] == '#') {
                r = false;
                break;
            }
        }
        if (r) {
            for(int j = 0; j < h; j++) {
                a[j][i] = '*';
            }
        }
    }
    for (int i = 0; i < h; i++) {
        bool o = false;
        for(int j = 0; j < w; j++) {
            if (a[i][j] != '*') {
                o = true;
                cout << a[i][j];
            }
        }
        if (o) {
            cout << endl;
        }
    }
}