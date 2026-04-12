#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    vector<int> d1(h + 1,0), d2(w + 1,0);

    for (int i = 0; i < h; i++){
        int white = 0;
        for (int j = 0; j < w; j++) {
            cin >> grid.at(i).at(j);
                if (grid.at(i).at(j) == '.') white++;
                else white = 0;
        }
        if (white == w) d1.at(i) = 1;
    }

    for (int i = 0; i < w; i++) {
        int white = 0;
        for (int j = 0; j < h; j++) {
            if (grid.at(j).at(i) == '.') white++;
            else white = 0;
        }
        if (white == h) d2.at(i) = 1;
    }

    for (int i = 0; i < h; i++) {
        if (d1.at(i) == 1) continue;
        else {
            for (int j = 0; j < w; j++) {
                if (d2.at(j) == 1) continue;
                else {
                    cout << grid.at(i).at(j);
                }
            }
        cout << endl;
        }
    }
}