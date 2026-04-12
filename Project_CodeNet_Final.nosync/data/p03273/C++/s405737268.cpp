#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int h, w;
    cin >> h >> w;

    char a[105][105];
    vector<bool> row(h, false);
    vector<bool> col(w, false);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        if (row[i]) {
            for (int j = 0; j < w; j++) {
                if (col[j]) cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}