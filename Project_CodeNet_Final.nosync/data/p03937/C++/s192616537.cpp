#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int H, W;
char A[10][10];
bool visited[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool dfs(int x, int y) {
    visited[x][y] = true;
    if (x == H-1 && y == W-1) {
        return true;
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (0 <= x+dx[i] && x+dx[i] < H &&
                0 <= y+dy[i] && y+dy[i] < W) {
                if (A[x+dx[i]][y+dy[i]] == '#') {
                    if (!visited[x+dx[i]][y+dy[i]] && i < 2) {
                        return dfs(x+dx[i], y+dy[i]);
                    }
                } 
            }
        }
    }
    return false;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    memset(visited, false, sizeof(visited));

    bool c = dfs(0, 0);
    bool d = true;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#' && !visited[i][j]) {
                d = false;
            }
        }
        if (!d) break;
    }

    cout << (c && d ? "Possible" : "Impossible") << endl;
  
    return 0;
}
