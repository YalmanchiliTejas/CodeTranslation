
#include <bits/stdc++.h>

using namespace std;

int h, w;
char a[100][100];

void delete_row(int row_i) {
    for (int i = row_i; i < h - 1; ++i) {
        for (int j = 0; j < w; ++j) {
            a[i][j] = a[i + 1][j];
        }
    }
}

void delete_column(int col_j) {
    for (int j = col_j; j < w - 1; ++j) {
        for (int i = 0; i < h; ++i) {
            a[i][j] = a[i][j + 1];
        }
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = h - 1; i >= 0; --i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') break;
            if (j == w - 1) {
                delete_row(i);
                h--;
            }
        }
    }

    for (int j = w - 1; j >= 0; --j) {
        for (int i = 0; i < h; ++i) {
            if (a[i][j] == '#') break;
            if (i == h - 1) {
                delete_column(j);
                w--;
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << a[i][j];
        }
        cout << '\n';
    }

    return 0;
}
