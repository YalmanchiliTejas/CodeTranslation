#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
char matrix[MAXN][MAXN];
bool removablesV[MAXN];
bool removablesH[MAXN];

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++){
        removablesH[i] = false;
        cin >> matrix[i];
    }
    for (int j = 0; j < w; j++){
        removablesV[j] = false;
    }
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < h; i++) {
            if (removablesH[i])
                continue;
            bool removable = true;
            for (int j = 0; j < w; j++) {
                if (matrix[i][j] == '#') {
                    removable = false;
                    break;
                }
            }
            removablesH[i] = removable;
            changed = removable || changed;
        }
        for (int i = 0; i < w; i++) {
            if (removablesV[i])
                continue;
            bool removable = true;
            for (int j = 0; j < h; j++) {
                if (matrix[j][i] == '#') {
                    removable = false;
                    break;
                }
            }
            removablesV[i] = removable;
            changed = removable || changed;
        }
    }
    for (int i = 0; i < h; i++){
        if (removablesH[i])
            continue;
        for (int j = 0; j < w; j++){
            if (!removablesV[j])
                cout << matrix[i][j];
        }
        cout << endl;
    }
}


