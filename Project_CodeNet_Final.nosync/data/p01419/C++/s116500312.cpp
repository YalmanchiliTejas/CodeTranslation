#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using P = pair<int, int>;

constexpr int INF = 1e9;

int main() {
    int R, C, M;
    cin >> R >> C >> M;
    vector<string> v(R);
    for(int i=0; i<R; ++i) {
        cin >> v[i];
    }
    // 0: per, 1: on, 2: off
    vector<vector<vector<int>>> cost(3, vector<vector<int>>(R, vector<int>(C)));
    for(int i=0; i<3; ++i) {
        for(int j=0; j<R; ++j) {
            for(int k=0; k<C; ++k) {
                cin >> cost[i][j][k];
            }
        }
    }
    vector<P> task(M);
    for(int i=0; i<M; ++i) {
        cin >> task[i].first >> task[i].second;
    }
    int res = cost[1][task[0].first][task[0].second] + cost[2][task[0].first][task[0].second];
    vector<vector<int>> prev_t(R, vector<int>(C, INF));
    prev_t[task[0].first][task[0].second] = 0;
    int t = 0;
    for(int i=1; i<M; ++i) {
        queue<P> que;
        que.push(task[i-1]);
        vector<vector<int>> d(R, vector<int>(C, INF));
        vector<vector<P>> prev(R, vector<P>(C, P{-1, -1}));
        d[task[i-1].first][task[i-1].second] = t;
        while(!que.empty()) {
            P p = que.front(); que.pop();
            int dr[4] = {0, 1, 0, -1},
                dc[4] = {1, 0, -1, 0};
            for(int j=0; j<4; ++j) {
                int nr = p.first + dr[j],
                    nc = p.second + dc[j];
                if(nr < 0 || R <= nr || nc < 0 || C <= nc || v[nr][nc] == '#') {
                    continue;
                }
                if(d[nr][nc] == INF) {
                    d[nr][nc] = d[p.first][p.second] + 1;
                    prev[nr][nc] = p;
                    que.push(make_pair(nr, nc));
                }
            }
        }
        int r = task[i].first, c = task[i].second;
        t = d[r][c];
        while(r != task[i-1].first || c != task[i-1].second) {
            if(prev_t[r][c] != INF) {
                res += min((d[r][c] - prev_t[r][c]) * cost[0][r][c], cost[1][r][c] + cost[2][r][c]);
            } else {
                res += cost[1][r][c] + cost[2][r][c];
            }
            prev_t[r][c] = d[r][c];
            P p = prev[r][c];
            r = p.first, c = p.second;
        }
    }
    cout << res << endl;
}
