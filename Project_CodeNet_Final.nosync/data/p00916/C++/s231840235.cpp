#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200 + 10;

map<int, int> IDX, IDY;
int L[MAXN], R[MAXN], B[MAXN], T[MAXN];
bool vis[MAXN][MAXN], canX[MAXN][MAXN], canY[MAXN][MAXN];
int N, Nx, Ny;

bool floodfill(int x, int y) {
    if (x < 0 || x >= Nx || y < 0 || y >= Ny) return false;
    bool flag = true;
    if (!vis[x][y]) {
        vis[x][y] = true;
        if (canX[x][y]) flag &= floodfill(x - 1, y);
        if (canX[x + 1][y]) flag &= floodfill(x + 1, y);
        if (canY[x][y]) flag &= floodfill(x, y - 1);
        if (canY[x][y + 1]) flag &= floodfill(x, y + 1);
    }
    return flag;
}

int main() {
    while (scanf("%d", &N) == 1 && N) {
        IDX.clear(); IDY.clear();
        for (int i = 0; i < N; ++ i) {
            scanf("%d%d%d%d", L + i, T + i, R + i, B + i);
            IDX[B[i]] = 0; IDX[T[i]] = 0;
            IDY[L[i]] = 0; IDY[R[i]] = 0;
        }
        Nx = Ny = 0;
        for (auto &x : IDX) x.second = Nx ++;
        for (auto &y : IDY) y.second = Ny ++;
        for (int i = 0; i <= Nx; ++ i) {
            for (int j = 0; j <= Ny; ++ j) {
                canX[i][j] = canY[i][j] = true;
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < N; ++ i) {
            L[i] = IDY[L[i]]; R[i] = IDY[R[i]];
            B[i] = IDX[B[i]]; T[i] = IDX[T[i]];
            for (int j = L[i]; j < R[i]; ++ j) canX[T[i]][j] = canX[B[i]][j] = false;
            for (int j = B[i]; j < T[i]; ++ j) canY[j][L[i]] = canY[j][R[i]] = false;
        }
        int ret = 1;
        for (int i= 0; i < Nx; ++ i) {
            for (int j = 0; j < Ny; ++ j) {
                if (!vis[i][j]) ret += floodfill(i, j);
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}