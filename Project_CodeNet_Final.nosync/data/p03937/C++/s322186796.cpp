#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<numeric>
#include<math.h>
#include<deque>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
bool dfs ( int a, int b, vector<vector<char>>& hw, vector<vector<bool>>& flg, int h, int w ) {
    if ( a >= h || b >= w ) return false;
    flg[a][b] = true;
    bool ng = false;
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    int cnt = 0;
    bool ok = true;
    rep(i, 2) {
        int next_y = a + dy[i];
        int next_x = b + dx[i];
        if ( next_y >= h || next_x >= w ) continue;
        if ( hw[next_y][next_x] == '#' ) {
            ok = dfs(next_y, next_x, hw, flg, h, w);
            ++cnt;
        }
    }
    if ( !ok ) return false;
    if ( cnt == 2 ) return false;
    else            return true;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> hw(h, vector<char>(w));
    vector<vector<bool>> flg(h, vector<bool>(w, false));
    rep(i, h) rep(j, w) cin >> hw[i][j];
    bool ok = dfs(0, 0, hw, flg, h, w);
    if ( !ok ) {
        cout << "Impossible" << endl;
        return 0;
    }
    rep(i, h) rep(j, w) {
        if ( hw[i][j] == '#' && !flg[i][j] ) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}
