#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <cmath>
#include <array>
#include <iomanip>


using namespace std;

void No() {
    cout << "Impossible\n";
    exit(0);
}


void Yes() {
    cout << "Possible\n";
    exit(0);
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;

            if (c == '#') {
                v[i].push_back(j);
            }
        }
    }
    int mx_prev = -1;
    for (auto& cur : v) {
        if (cur.size() == 0) {
            No();
        }
        if (!(cur.back() - *cur.begin() == (int)cur.size() - 1)) {
            No();
        }
        if (mx_prev > *cur.begin()) {
            No();
        }
        mx_prev = cur.back();
    }
    if (v[0][0] != 0) {
        No();
    }
    if (v[h - 1].back() != w - 1) {
        No();
    }
    Yes();
}
