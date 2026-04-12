#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a.at(i);
    }


    vector<int> col(h, 0), row(w, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a.at(i).at(j) == '#') {
                col.at(i) = 1;
                break;
            }
        }
    }
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            if (a.at(i).at(j) == '#') {
                row.at(j) = 1;
                break;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (col.at(i) == 1 && row.at(j) == 1) {
                cout << a.at(i).at(j);
            }
        }
        if (col.at(i) == 1) {
            cout << endl;
        }
    }
}
