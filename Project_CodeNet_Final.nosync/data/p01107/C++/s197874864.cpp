#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int di[] = {0, 1, 0, -1};
int dj[] = {-1, 0, 1, 0};
int h, w;
vector<string> field;
bool dfs(int ci, int cj, int ck) {
    field[ci][cj] = '@';
    for (int dk = 0; dk < 4; dk++) {
        int nk = (ck - 1 + dk + 4) % 4;
        int ni = ci + di[nk], nj = cj + dj[nk];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (ni == 0 && nj == 0) return true;
        if (field[ni][nj] == '.') {
            if (dfs(ni, nj, nk)) return true;
        }
    }
    field[ci][cj] = 'x';
    return false;
}

int main() {
    while (cin >> h >> w, h) {
        field.resize(h);
        for (string& row: field) cin >> row;
        bool ok = dfs(0, 0, 0);
        ok &= field[0][0] == '@';
        ok &= field[h - 1][0] == '@';
        ok &= field[0][w - 1] == '@';
        ok &= field[h - 1][w - 1] == '@';
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
