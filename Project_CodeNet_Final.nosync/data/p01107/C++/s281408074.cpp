#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, m, n) for (int i = (m); i < (n); i++)

void init() {}

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

int N, M;
char A[202][202];
bool vis[202][202];
int cnt[202][202];
bool dfs(int i, int j, int dir, int res) {
    // cout << i << " " << j << endl;
    if (i == 0 && j == 0 && res == 3) return true;
    if (vis[i][j] && res > cnt[i][j]) return false;
    vis[i][j] = true;
    if ((i == N - 1 && j == M - 1) || (i == N - 1 && j == 0) || (i == 0 && j == M - 1)) res++;
    cnt[i][j] = res;
    {
        int k = 1;
        int d = (dir + k) % 4;
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] != '#') {
            if (dfs(nx, ny, d, res))
                return true;
            else
                return false;
        }
    }
    {
        int k = 0;
        int d = (dir + k) % 4;
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] != '#') {
            if (dfs(nx, ny, d, res))
                return true;
            else
                return false;
        }
    }
    {
        int k = 3;
        int d = (dir + k) % 4;
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] != '#') {
            if (dfs(nx, ny, d, res))
                return true;
            else
                return false;
        }
    }
    {
        int k = 2;
        int d = (dir + k) % 4;
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] != '#') {
            if (dfs(nx, ny, d, res))
                return true;
            else
                return false;
        }
    }
    // FOR(k, 1, 5) {
    //     int d = (dir + k) % 4;
    //     if (d == (dir + 2) % 4) continue;
    //     int nx = i + dx[d];
    //     int ny = j + dy[d];
    //     if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] != '#') {
    //         if (dfs(nx, ny, d, res)) return true;
    //     }
    // }
    vis[i][j] = false;
    return false;
}
bool solve() {
    cin >> N >> M;
    if (N == 0) return false;
    REP(i, N) {
        REP(j, M) {
            cin >> A[i][j];
            vis[i][j] = false;
            cnt[i][j] = 0;
        }
    }
    if (dfs(0, 0, 3, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return true;
}
signed main() {
    init();
    while (solve())
        ;
}
