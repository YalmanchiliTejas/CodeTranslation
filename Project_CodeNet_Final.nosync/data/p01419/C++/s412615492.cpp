#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int h, w, m;
    cin >> h >> w >> m;
    vector<vector<int>> cost1(h+2, vector<int>(w+2, 0));
    auto cost2 = cost1; auto cost3 = cost1;
    auto grid = cost1;
    auto visited = cost1;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            grid[i+1][j+1] = (s[j] == '.');
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> cost1[i+1][j+1];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> cost2[i+1][j+1];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> cost3[i+1][j+1];
        }
    }
    int time = 1;
    vector<vector<vector<int>>> times(h+2, vector<vector<int>> (w+2));
    int sy, sx;
    cin >> sy >> sx;
    sy++; sx++;
    array<int, 4> dy{-1, 1, 0, 0}, dx{0, 0, 1, -1};
    for (int i = 1; i < m; ++i) {
        int y, x;
        cin >> y >> x;
        y++; x++;

        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < w; ++k) {
                visited[j+1][k+1] = 0;
            }
        }
        stack<tuple<int, int, int>> S;
        S.emplace(sy, sx, time);
        while(!S.empty()){
            int yy, xx, t; tie(yy, xx, t) = S.top(); S.pop();
            visited[yy][xx] = t;

            for (int k = 0; k < 4; ++k) {
                if(grid[yy+dy[k]][xx+dx[k]] && !visited[yy+dy[k]][xx+dx[k]]){
                    S.emplace(yy+dy[k], xx+dx[k], t+1);
                }
            }
        }
        int yy = y, xx = x;

        int ttime = visited[y][x];
        times[yy][xx].emplace_back(ttime);
        while(ttime > time){
            for (int k = 0; k < 4; ++k) {
                if(visited[yy+dy[k]][xx+dx[k]] == max(time, visited[yy][xx]-1)){
                    yy += dy[k];
                    xx += dx[k];
                    break;
                }
            }
            ttime--;
            times[yy][xx].emplace_back(ttime);
        }
        time = visited[y][x];
        sy = y, sx = x;
    }
    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(!times[i][j].empty()){
                vector<int> dp(times[i][j].size(), MOD), dq(times[i][j].size(), MOD);
                dp[0] = cost2[i][j];
                dq[0] = cost2[i][j] + cost3[i][j];
                for (int k = 1; k < times[i][j].size(); ++k) {
                    dp[k] = min(
                            dp[k-1]+cost1[i][j]*(times[i][j][k]-times[i][j][k-1]),
                            dq[k-1]+cost2[i][j]
                            );
                    dq[k] = min(
                            dp[k-1]+cost1[i][j]*(times[i][j][k]-times[i][j][k-1])+cost3[i][j],
                            dq[k-1]+cost2[i][j]+cost3[i][j]
                            );
                }
                ans += dq.back();
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
