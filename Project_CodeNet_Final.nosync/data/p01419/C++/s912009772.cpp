#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(_v) for(auto _x:_v){cout<<_x<<" ";}cout<<endl
#define printVS(_vs) for(auto _x : _vs){cout << _x << endl;}
#define printVV(_vv) for(auto _v:_vv){for(auto _x:_v){cout<<_x<<" ";}cout<<endl;}
#define printP(_p) cout << _p.first << " " << _p.second << endl
#define printVP(_vp) for(auto _p : _vp) printP(_p);

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
const int inf = 1e9;
const int mod = 1e9 + 7;

// #define double long double

typedef complex<double> P;
typedef vector<P> G;
#define here(g, i) g[i]
#define next(g, i) g[(i + 1) % g.size()]
#define prev(g, i) g[(i - 1 + g.size()) % g.size()]
const double EPS = 1e-6;
const double INF = 1e12;
const double PI = acos(-1);

// N, E, S, W
const int dx[4] = {-1, 0,  1,  0};
const int dy[4] = { 0, 1,  0, -1};

bool inside(int x, int y, int H, int W) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int H, W, m;
    cin >> H >> W >> m;
    vector<string> s(H);
    rep(i, H) cin >> s[i];
    vvi power(H, vi(W));
    rep(i, H) rep(j, W) cin >> power[i][j];
    vvi on(H, vi(W));
    rep(i, H) rep(j, W) cin >> on[i][j];
    vvi off(H, vi(W));
    rep(i, H) rep(j, W) cin >> off[i][j];
    vector<Pii> task(m);
    rep(i, m) cin >> task[i].first >> task[i].second;

    vvvi time(H, vvi(W));
    time[task[0].first][task[0].second].emplace_back(0);
    std::function<int(int,int,int,int,int,int,int)> dfs = [&](int x, int y, int px, int py, int gx, int gy, int t) {
        if (x == gx && y == gy) {
            return t;
        }

        rep(k, 4) {
            int nx = x + dx[k], ny = y + dy[k];
            if (!inside(nx, ny, H, W)) continue;
            if (s[nx][ny] == '#') continue;
            if (nx == px && ny == py) continue;
            time[nx][ny].emplace_back(t);
            int ret = dfs(nx, ny, x, y, gx, gy, t + 1);
            if (ret < inf) return ret;
            time[nx][ny].pop_back();
        }

        return inf;
    };

    int t = 1;
    rep(i, m - 1) {
        t = dfs(task[i].first, task[i].second, -1, -1, task[i + 1].first, task[i + 1].second, t);
    }

    // rep(i, H) {
    //     rep(j, W) {
    //         cout << i << " " << j << ": ";
    //         printV(time[i][j]);
    //     }
    // }

    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (time[i][j].empty()) {
                continue;
            }
            ans += on[i][j];
            rep(k, (int)time[i][j].size() - 1) {
                ans += min(power[i][j] * (time[i][j][k + 1] - time[i][j][k]), off[i][j] + on[i][j]);
            }
            ans += off[i][j];
        }
    }

    cout << ans << endl;

}