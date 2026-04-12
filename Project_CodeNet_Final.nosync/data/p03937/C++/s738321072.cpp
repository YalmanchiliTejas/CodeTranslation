#include <iostream>
using namespace std;

const int MAX_H = 10;

string a[MAX_H];

int main() {
    int h, w;
    cin >> h >> w;

    for (int r = 0; r < h; r++) {
        cin >> a[r];
    }

    int cnt = 0;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (a[r][c] == '#') cnt++;
        }
    }

    if (cnt == w + h - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}
