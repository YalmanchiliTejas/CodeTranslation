#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> color(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> color.at(i).at(j);
        }
    }

    // 黒いマスが存在する行を記録
    vector<bool> check_row(h);
    for (int i = 0; i < h; i++) {
        check_row.at(i) = false;
        for (int j = 0; j < w; j++) {
            if (color.at(i).at(j) == '#') {
                check_row.at(i) = true;
            }
        }
    }
    // 黒いマスが存在する列を記録
    vector<bool> check_column(w);
    for (int j = 0; j < w; j++) {
        check_column.at(j) = false;
        for (int i = 0; i < h; i++) {
            if (color.at(i).at(j) == '#') {
                check_column.at(j) = true;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        if (check_row.at(i) == false) {
            continue;
        }
        for (int j = 0; j < w; j++) {
            if (check_column.at(j) == false) {
                continue;
            }
            cout << color.at(i).at(j);
        }
        cout << endl;
    }
    cout << endl;
}