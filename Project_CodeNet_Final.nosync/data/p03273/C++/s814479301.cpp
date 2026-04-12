#include <bits/stdc++.h>
#define W '.'
#define B '#'
using namespace std;


int main() {
    int h, w;

    cin >> h >> w;

    char a[h][w];
    bool allWh[h];
    bool allWw[w];

    for (int i = 0; i < h; i++) {
        allWh[i] = true;
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] != W) allWh[i] = false;
        }
    }

    for (int j = 0; j < w; j++) {
        allWw[j] = true;
        for (int i = 0; i < h; i++) {
            if (a[i][j] != W) allWw[j] = false;
        }
    }

    for (int i = 0; i < h; i++) {
        if (allWh[i]) continue;
        for (int j = 0; j < w; j++) {
            if (allWw[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
