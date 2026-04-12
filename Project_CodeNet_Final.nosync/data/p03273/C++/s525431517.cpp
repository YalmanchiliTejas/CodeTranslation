#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    int h, w;
    cin >> h >> w;

    char c[101][100];
    char d[101][100];

    for (int i = 0; i < h; i++) {
        cin >> c[i];
    }

    int x = 0;
    for (int i = 0; i < h; i++) {
        int b = 1;
        for (int j = 0; j < w; j++) {
            if (c[i][j] != '.') b = 0;
        }
        for (int j = 0; j < w; j++) {
            d[x][j] = c[i][j];
        }
        if (!b) x++;
    }

    int y = 0;
    for (int j = 0; j < w; j++) {
        int b = 1;
        for (int i = 0; i < x; i++) {
            if (d[i][j] != '.') b = 0;
        }
        for (int i = 0; i < x; i++) {
            c[i][y] = d[i][j];
        }
        if (!b) y++;
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << c[i][j];
        }
        cout << '\n';
    }

    return 0;
}