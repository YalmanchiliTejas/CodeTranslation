#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> a;
    for (int i = 0; i < h; ++i) {
        string tmp;
        cin >> tmp;
        if (tmp.find("#") != string::npos)
            a.push_back(tmp);
    }

    vector<int> ignore_columns;
    for (int col = 0; col < w; ++col) {
        bool only_white = true;
        for (int row = 0; row < a.size(); ++row) {
            if (a[row][col] == '#') {
                only_white = false;
                break;
            }
        }
        if (!only_white)
            ignore_columns.push_back(col);
    }

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < w; ++j) {
            if (find(ignore_columns.begin(), ignore_columns.end(), j) !=
                ignore_columns.end())
                cout << a[i][j];
        }
        cout << '\n';
    }
}
