#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> masu(h, vector<char> (w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> masu.at(i).at(j);
        }
    }
    vector<bool> x(w, false);
    vector<bool> y(h, false);
    for (int i = 0; i < h; i++) {
        bool tf = true;
        for (int j = 0; j < w; j++) {
            if (masu.at(i).at(j) == '#') {
                tf = false;
                goto next1;
            }
        }
        y.at(i) = true;
        next1:;
    }
    for (int i = 0; i < w; i++) {
        bool tf = true;
        for (int j = 0; j < h; j++) {
            if (masu.at(j).at(i) == '#') {
                tf = false;
                goto next2;
            }
        }
        x.at(i) = true;
        next2:;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (y.at(i)) goto next3;
            if (!x.at(j) && !y.at(i)) {
                cout << masu.at(i).at(j);
            }
        }
        cout << endl;
        next3:;
    }
}
