#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int R, C, M, keep[60][60], on[60][60], off[60][60], X[2525], Y[2525];
bool checked[60][60];
vector<int> pass[60][60];
char board[60][60];
int tot = 0;

void read_input(int A[][60]) {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

int dfs(int x, int y, int tx, int ty, int d) {
    if(x == tx && y == ty) return d;
    for(int k=0; k<4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if(board[nx][ny] == '#' || checked[nx][ny]) continue;
        checked[nx][ny] = true;
        int val = dfs(nx, ny, tx, ty, d+1);
        checked[nx][ny] = false;
        if(val) {
            pass[x][y].push_back(tot + d);
            return val;
        }
    }
    return 0;
}

void solve() {
    for(int i=0; i<M-1; i++) {
        checked[ X[i] ][ Y[i] ] = true;
        tot += dfs(X[i], Y[i], X[i+1], Y[i+1], 0);
        checked[ X[i] ][ Y[i] ] = false;
    }
    pass[ X[M-1] ][ Y[M-1] ].push_back(tot);

    int ans = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            int N = pass[i][j].size();
            if(!N) continue;
            ans += on[i][j] + off[i][j];
            for(int k=0; k<N-1; k++) {
                int diff = pass[i][j][k+1] - pass[i][j][k];
                int vl = on[i][j] + off[i][j];
                int vr = keep[i][j] * diff;
                ans += min(vl, vr);
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d%d%d", &R, &C, &M);
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            scanf(" %c", &board[i][j]);
        }
    }
    read_input(keep);
    read_input(on);
    read_input(off);
    for(int i=0; i<M; i++) {
        scanf("%d%d", &X[i], &Y[i]);
    }

    solve();
    return 0;
}
