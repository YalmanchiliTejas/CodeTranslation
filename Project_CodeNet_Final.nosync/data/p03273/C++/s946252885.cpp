#include <bits/stdc++.h>
using namespace std;

string a[110];
bool row[110], column[110];

int main() {
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; i++) cin >> a[i];
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') row[i] = column[j] = true;
        }
    }

    for (int i = 0; i < H; i++) {
        if (!row[i]) continue;
        for (int j = 0; j < W; j++) {
            if (!column[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
}