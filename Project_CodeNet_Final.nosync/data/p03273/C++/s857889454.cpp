#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> data(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> data.at(i).at(j);
        }
    }

    vector<bool> line(h, false);
    vector<bool> row(w, false);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (data.at(i).at(j) == '#') {
                line.at(i) = true;
                row.at(j) = true;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        if (line.at(i)) {
            for (int j = 0; j < w; j++) {
                if ( row.at(j)) {
                    cout << data.at(i).at(j);
                }
            }      
            cout << endl;
        }
    }
}