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

    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (a[r][c] != '#') continue;

            int cnt = 0;
            if (r - 1 >= 0 && a[r - 1][c] == '#') cnt++;
            if (c - 1 >= 0 && a[r][c - 1] == '#') cnt++;
            if (cnt >= 2) {
                cout << "Impossible" << endl;
                return 0;
            }
            cnt = 0;
            if (r + 1 < h && a[r + 1][c] == '#') cnt++;
            if (c + 1 >= 0 && a[r][c + 1] == '#') cnt++;
            if (cnt >= 2) {
                cout << "Impossible" << endl;
                return 0;
            }
            cnt = 0;
        }

    }

    cout << "Possible" << endl;
    return 0;
}
