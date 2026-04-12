#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> table(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> table.at(i).at(j);
        }
    }

    for (int i = 0; i < H; i++) {
        bool shift = true;

        for (int j = 0; j < W; j++) {
            if (table.at(i).at(j) != '.') {
                shift = false;
                break;
            }
        }

        if (shift) {
            for (int j = i; j < H - 1; j++) {
                for (int k = 0; k < W; k++) {
                    table.at(j).at(k) = table.at(j + 1).at(k);
                }
            }
            i--;
            H--;
        }
    }

    for (int i = 0; i < W; i++) {
        bool shift = true;

        for (int j = 0; j < H; j++) {
            if (table.at(j).at(i) != '.') {
                shift = false;
                break;
            }
        }

        if (shift) {
            for (int j = i; j < W - 1; j++) {
                for (int k = 0; k < H; k++) {
                    table.at(k).at(j) = table.at(k).at(j + 1);
                }
            }
            i--;
            W--;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << table.at(i).at(j);
        }
        cout << endl;
    }
}