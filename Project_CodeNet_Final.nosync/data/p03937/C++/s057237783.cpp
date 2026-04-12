#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

constexpr int MOD = 1000000007;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;

int main() {
    int H, W;
    string g[8], m[8];
    cin >> H >> W;
    for (int j = 0; j < H; ++j) {
        cin >> g[j];
        m[j] = string(W, '.');
    }

    int h, w;
    h = 0; w = 0;
    while (! (h == H-1 && w == W-1)) {
        m[h][w] = '#';
        if (h < H-1 && g[h+1][w] == '#') {
            ++h;
        } else if (w < W-1 && g[h][w+1] == '#') {
            ++w;
        } else {
            break;
        }
    }

    if (h == H-1 && w == W-1) {
        m[H-1][W-1] = '#';
        bool ok = true;
        for (int j = 0; j < H; ++j) {
            if (g[j] != m[j]) {
                ok = false;
            }
        }
        cout << (ok ? "Possible" : "Impossible") << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
