#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a.at(i).at(j);
        }
    }

    int nx = 0, ny = 0;
    a.at(0).at(0) = '.';
    for (int i = 0; i < h + w - 2; i++) {
        if (nx + 1 < w && a.at(ny).at(nx + 1) == '#') nx++;
        else if (ny + 1 < h && a.at(ny + 1).at(nx) == '#') ny++;
        else {
            cout << "Impossible" << endl;
            return 0;
        }
        a.at(ny).at(nx) = '.';
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a.at(i).at(j) == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
}