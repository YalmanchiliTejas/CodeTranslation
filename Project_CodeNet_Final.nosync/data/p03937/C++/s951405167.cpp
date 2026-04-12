#include <bits/stdc++.h>

using namespace std;

const int MAX_H = 8, MAX_W = 8;

int h, w;

char a[MAX_H + 1][MAX_W + 1];

bool canRight(int i, int j) {
    return j < w && a[i][j + 1] == '#';
}

bool canDown(int i, int j) {
    return i < h && a[i + 1][j] == '#';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }

    int counter = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i][j] == '#') {
                counter++;
            }
        }
    }

    if (counter != h + w - 1) {
        cout << "Impossible" << endl;

        return 0;
    }

    int i = 1, j = 1;
    while (i < h && j < w) {
        if (canRight(i, j) && canDown(i, j)) {
            cout << "Impossible" << endl;

            return 0;
        }

        if (!canRight(i, j) && !canDown(i, j)) {
            cout << "Impossible" << endl;

            return 0;
        }

        if (canRight(i, j)) {
            j++;

            continue;
        }

        if (canDown(i, j)) {
            i++;

            continue;
        }
    }

    cout << "Possible" << endl;

    return 0;
}
