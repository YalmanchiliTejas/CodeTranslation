#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);

    for (int i = 0; i < h; i++)
        cin >> grid[i];

    vector<int> tate(h), yoko(w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '#') {
                tate[i] = 1;
                break;
            }
            
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (grid[j][i] == '#') {
                yoko[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        if (tate[i]) {
            for (int j = 0; j < w; j++) {
                if (yoko[j])
                    cout << grid[i][j];
            }
            cout << endl;
        }
    }
}