#include <iostream>
using namespace std;
int main() {
    int h, w;
    cin >> h >> w;
    int a[h][w], row[h] = {}, col[w] = {};
    string s;
    for (int i=0; i<h; i++) {
        cin >> s;
        for (int j=0; j<w; j++) {
            if (s[j] == '#') {
                a[i][j] = 1;
                row[i]++;
                col[j]++;
            } else {
                a[i][j] = 0;
            }
        }
    }
    for (int i=0; i<h; i++) {
        if (row[i] != 0) {
            for (int j=0; j<w; j++) {
                if (col[j] != 0) {
                    cout << ((a[i][j] == 0) ? '.' : '#');
                }
            }
            cout << endl;
        }
    }
}