// Grid Compression

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ios>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

int h, w;

bool is_in(vector<int> v, int n) {
    auto itr = find(v.begin(), v.end(), n);
    if( itr != v.end() ) {
        return true;
    }
    return false;
}

int main() {
    cin >> h >> w;

    char a[h][w];

    // 標準入力から読み込めていない？
    for (int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> erase_row;
    vector<int> erase_col;
    for (int row = 0; row < h; row++) {
        bool is_erase = true;
        for(int col = 0; col < w; col++) {
            if (a[row][col] == '#') {
                is_erase = false;
            }
        }
        if (is_erase) {
            erase_row.push_back(row);
        }
    }

    for (int col = 0; col < w; col++) {
        bool is_erase = true;
        for(int row = 0; row < h; row++) {
            if (a[row][col] == '#') {
                is_erase = false;
            }
        }
        if (is_erase) {
            erase_col.push_back(col);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (is_in(erase_row, i) || is_in(erase_col, j)) {
                continue;
            }
            cout << a[i][j];
        }
        if (!is_in(erase_row, i)) {
            cout << endl;
        }

    }

    return 0;
}
