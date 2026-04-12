#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cassert>
#pragma GCC optimize("O3")
#pragma comment(linker, "STACK:36777216")
using namespace std;
using i64 = int64_t;
constexpr i64 mod = 17;
using vi = vector<i64>;
using vvi = vector<vi>;
using ii = pair<i64, i64>;
using vii = vector<ii>;

char b[100][100];

bool isgoodrow(int i) {
    for (int j = 0; j < 100; j++) {
        if (b[i][j]) return true;
    }
    return false;
}

bool isgoodcolumn(int i) {
    for (int j = 0; j < 100; j++) {
        if (b[j][i]) return true;
    }
    return false;
}

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                b[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        int k = 0;
        for (int j = 0; j < 100; j++) {
            if (isgoodrow(i) && isgoodcolumn(j)) {
                k = 1;
                if (b[i][j]) {
                    cout << "#";
                } else {
                    cout << ".";
                }
            }
        }
        if (k) {
            cout << endl;
        }
    }
}
