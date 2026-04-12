#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define INF (ll)(1e18)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }


int dy[] = {1, 0};
int dx[] = {0, 1};

int h, w;
string s[10];
int flg;

void dfs(int y, int x, vector<vector<int> > table) {
    if (y == h - 1 && x == w - 1) {
        rep(i, h) rep(j, w) {
            if (s[i][j] == '#' && table[i][j] == 0) {
                return;
            }
            if (i == h - 1 && j == w - 1) {
                flg = 1;
                return;
            }
        }
    }
    
    rep(i, 2) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny == h || nx == w || s[ny][nx] == '.') continue;
        
        table[ny][nx] = 1;
        dfs(ny, nx, table);
        table[ny][nx] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    
    cin >> h >> w;
    rep(i, h) cin >> s[i];
    
    vector<vector<int> > v(10, vector<int>(10));
    v[0][0] = 1;
    
    dfs(0, 0, v);
    if (flg) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}
