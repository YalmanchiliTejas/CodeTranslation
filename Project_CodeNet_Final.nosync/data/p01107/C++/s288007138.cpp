#include"bits/stdc++.h"
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for (int i = b - 1; i > a; i--)
#define RREP(i, n) RFOR(i, 0, n)
#define rep(i, a, b) for (auto i = a; i < b; i++)
#define rrep(i, a, b) for (auto i = b; i > a; i--)
#define range(i, a, b) (a <= i && i < b)
#define fi first
#define fs first
#define se second
#define sc second
#define ll long long
using namespace std;
using vec = vector<int>;
using mat = vector<vec>;
typedef pair<int, int> P;

int h, w;
vector<string> s;
int dx[] = { 0,1,0,-1 }, dy[] = { -1,0,1,0 };

bool make(){
    bool flag = false;
    REP(i, h) REP(j, w) {
        if (s[i][j] == '#') continue;
        int check = 0;
        REP(k, 4) {
            int x = i + dx[k], y = j + dy[k];
            if (0 <= x && x < h && 0 <= y && y < w && s[x][y] == '.') check++;
        }
        if (check <= 1) s[i][j] = '#', flag = true;
    }
    return flag;
}

mat used(50,vec(50));
vector<P> nx;

bool dfs(int x, int y, int d,int pre) {

    if (nx[d].fi == x && nx[d].se == y)
    {
        ++d;
        if (d == 4)
        {
            return true;
        }
    }

    REP(i, 4) {
        int k = (i + pre - 1 + 4) % 4;
        int xx = x + dx[k], yy = y + dy[k];
        if (0 <= xx && xx < h && 0 <= yy && yy < w && s[xx][yy] == '.' && used[xx][yy] == 0) {
            used[xx][yy] = 1;
            if (dfs(xx, yy, d, k))return true;
            //used[xx][yy] = 0;
            continue;
        }
    }

    return false;
}

bool check() {
    int x = 0, y = 0, d = 0;
    while (d<4) {
        bool flag = true;
        REP(i, 4) {
            int k = (i + d) % 4;
            int xx = x + dx[k], yy = y + dy[k];
            if (0 <= xx && xx < h && 0 <= yy && yy < w && s[xx][yy] == '.' && used[xx][yy] == 0) {
                x = xx; y = yy; used[x][y] = 1; flag = false;
                break;
            }
        }
        if (flag) return false;
        if (x == nx[d].fs && y == nx[d].sc) d++;
    } 
    return true;
}

void solve() {
    nx = { P(h - 1,0),P(h - 1,w - 1),P(0,w - 1),P(0,0) };
    s.resize(h);
    REP(i, h) cin >> s[i];

    /*while (1) {
        if (!make()) break;
    }*/

    //REP(i, h) {
    //    REP(j, w) cout << s[i][j];
    //    cout << endl;
    //}
    //cout << endl;

    if (s[0][0] == '#' || s[0][w - 1] == '#' || s[h - 1][0] == '#' || s[h - 1][w - 1] == '#') {
        cout << "NO" << endl;
        return;
    } 

    REP(i, 50) used[i].assign(50, 0);
    if (dfs(0,0,0,1)) cout << "YES" << endl;
    else cout << "NO" << endl;
} 

int main() {
    while (cin >> h >> w, h) solve();
}
