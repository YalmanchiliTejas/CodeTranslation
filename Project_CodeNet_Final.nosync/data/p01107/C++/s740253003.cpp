#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
#include <complex>
#include <queue>
using namespace std;
using P = pair<int, int>;
const int INF = 1<<30;
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e5 + 5;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M;
bool used[55][55];
vector<string> table;
bool dfs(int y, int x, int cnt, int dir)
{
    if(y == 0 and x == 0 and cnt == 3) return true;
    dir = (dir + 3) % 4;
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[(dir + i) % 4];
        int nx = x + dx[(dir + i) % 4];
        if(ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
        if(table[ny][nx] == '#' or used[ny][nx]) continue;

        if(y == N - 1 and x == 0) cnt++;
        if(y == N - 1 and x == M - 1) cnt++;
        if(y == 0 and x == M - 1) cnt++;
        used[ny][nx] = true;
        if(dfs(ny, nx, cnt, (dir + i) % 4)) return true;
    }
    return false;
}
signed main(void)
{
    while(cin >> N >> M, N or M)
    {
        table.resize(N);
        memset(used, false, sizeof(used));
        for(int i = 0; i < N; i++) cin >> table[i];
        //↓ start
        if(dfs(0, 0, 0, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
