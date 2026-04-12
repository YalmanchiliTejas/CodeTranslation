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

    vector<int> show_i;
    for (int i = 0; i < h; i++) {
        int c = 0;
        for (int j = 0; j < w; j++) {
            if (a.at(i).at(j) == '.') c++;
        }
        if (c < w) show_i.push_back(i);
    }

    vector<int> show_j;
    for (int j = 0; j < w; j++) {
        int c = 0;
        for (int i = 0; i < h; i++) {
            if (a.at(i).at(j) == '.') c++;
        }
        if (c < h) show_j.push_back(j);
    }

    for (int i : show_i) {
        for (int j : show_j) {
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
}