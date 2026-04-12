#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For(i, 0, n)
#define rrep(i, n) rFor(i, n, 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1000000007;
constexpr lint INF = mod * mod;
constexpr int MAX = 200010;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int h, w, m;
char c[55][55];
lint run[55][55], on[55][55], off[55][55];
pii pos[1010];
vector<int> visited_time[55][55];

int dfs(int x, int y, int px, int py, int tx, int ty, int cur){
    if(x == tx && y == ty){
        visited_time[tx][ty].push_back(cur);
        return cur;
    }
    rep(i, 4){
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < h && 0 <= ny && ny < w && c[nx][ny] == '.'){
            if(nx != px || ny != py){
                int ret = dfs(nx, ny, x, y, tx, ty, cur + 1);
                if(ret >= 0){
                    visited_time[x][y].push_back(cur);
                    return ret;
                }
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d%d%d", &h, &w, &m);
    rep(i, h)rep(j, w) scanf(" %c", &c[i][j]);
    rep(i, h)rep(j, w) scanf("%lld", &run[i][j]);
    rep(i, h)rep(j, w) scanf("%lld", &on[i][j]);
    rep(i, h)rep(j, w) scanf("%lld", &off[i][j]);
    rep(i, m) scanf("%d%d", &pos[i].fi, &pos[i].se);

    int now = 0;
    rep(i, m - 1){
        now = dfs(pos[i].fi, pos[i].se, -1, -1, pos[i + 1].fi, pos[i + 1].se, now);
    }
    lint ans = 0;
    rep(x, h)rep(y, w)if(!visited_time[x][y].empty()){
        visited_time[x][y].erase(unique(visited_time[x][y].begin(), visited_time[x][y].end()), visited_time[x][y].end());
        ans += on[x][y] + off[x][y];
        rep(i, visited_time[x][y].size() - 1){
            ans += min(off[x][y] + on[x][y], run[x][y] * (visited_time[x][y][i + 1] - visited_time[x][y][i]));
        }
    }
    printf("%lld\n", ans);
}
