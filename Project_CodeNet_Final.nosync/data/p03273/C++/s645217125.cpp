#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {
    int H, W;
    cin >> H >> W;
    bool down[H], across[W];
    char grid[H][W];

    for (int i = 0; i < H; i++) {
        scanf("%s", grid[i]);
        // cout << grid[i] << endl;
    }

    for (int i = 0; i < H; i++) {
        down[i] = false;
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') down[i] = true;
        }
        // cout << "down[" << i << "]: " << (down[i] ? "true" : "false") << endl;
    }

    for (int j = 0; j < W; j++) {
        across[j] = false;
        for (int i = 0; i < H; i++) {
            if (grid[i][j] == '#') across[j] = true;
        }
        // cout << "across[" << j << "]: " << (across[j] ? "true" : "false") << endl;
    }



    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (down[i] && across[j]) cout << grid[i][j];
            // cout << (down[i] && across[j] ? 't' : 'f');
        }
        if (down[i]) cout << endl;
        // cout << endl;
    }

    return 0;
}