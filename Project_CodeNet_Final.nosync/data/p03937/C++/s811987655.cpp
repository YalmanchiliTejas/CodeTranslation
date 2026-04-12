#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h + 1, vector<char>(w + 1));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    int x = 0, y = 0;
    a[0][0] = '.';
    while (x != w - 1 || y != h - 1) {
        if (a[y][x + 1] == '#') {
            ++x;
            a[y][x] = '.';
        } else if (a[y + 1][x] == '#') {
            ++y;
            a[y][x] = '.';
        } else {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}