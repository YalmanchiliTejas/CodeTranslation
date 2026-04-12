#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = (int)1e9 + 7;
int INF = (int)2e18;
// Comment out below and program paste
// #include "UnionFind.h"
// #include "power.h"

int H, W;
vector<vector<char>> A(10, vector<char>(10, '.'));
vector<vector<bool>> check(10, vector<bool>(10, false));

int ans = 0;
void dfs(int x, int y, int z) {
    check[x][y] = true;
    if (A[x + 1][y] == '#') dfs(x + 1, y, z + 1);
    if (A[x][y + 1] == '#') dfs(x, y + 1, z + 1);
    ans = max(ans, z);
}

signed main() {
    cin >> H >> W;
    int c = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (A[i][j] == '#') ++c;
        }
    }
    dfs(0, 0, 1);
    if (ans == c) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}