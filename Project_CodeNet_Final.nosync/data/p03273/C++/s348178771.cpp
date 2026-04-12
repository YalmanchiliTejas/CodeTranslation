#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));

    rep(i, H) {
        string line;
        cin >> line;
        rep(j, W) {
            grid.at(i).at(j) = line.at(j);
        }
    }

    vector<int> not_white_line;
    rep(i, H) {
        bool is_white_line = true;
        rep(j, W) {
            if (grid.at(i).at(j) == '#') {
                is_white_line = false;
                break;
            }
        }
        if (!is_white_line) {
            not_white_line.push_back(i);
        }
    }

    vector<int> not_white_row;
    rep(j, W) {
        bool is_white_row = true;
        rep(i, H) {
            if (grid.at(i).at(j) == '#') {
                is_white_row = false;
                break;
            }
        }
        if (!is_white_row) {
            not_white_row.push_back(j);
        }
    }

    for (int i : not_white_line) {
        for (int j : not_white_row) {
            cout << grid.at(i).at(j);
        }
        cout << endl;
    }
}