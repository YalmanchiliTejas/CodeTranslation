#include<bits/stdc++.h>
using namespace std;
//type
typedef long long ll;
using pii = pair<int, int>;
using vi = vector<int>;
//x * y * 1.0 can cause overflow
//constant
#define inf (int)(1e9+7)
#define mod (ll)(1e9+7)
#define eps 1e-10
//int dy[] = {0, 0, -1, 1, -1, 1, -1, 1}; //右、左、マイナス、プラス
//int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
//omission
#define eb emplace_back
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define all(v) v.begin(), v.end()
//manip
template<class T> bool chmax(T &a, T &b) {if (a < b) {a = b; return 1;} return 0;}
#define chmin(a, b) a = min(a, b)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end(), v.end());
#define ceil(a, b) a / b + !!(a % b)
template<class T> T power(T a, T b)
{return b ? power(a * a % inf, b / 2) * (b % 2 ? a : 1) % inf : 1;}
#define LB(v, x) (int)(lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (int)(upper_bound(v.begin(), v.end(), x) - v.begin())
//loop
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep3(i, st, n) for (int i = st; i < n; ++i)
//algorithm
//double pointer, l start, how many adds, can be 0 -> init r = l, sum = 0
//bfs, not x, y, i, j
//not !(i % 2), i % 2 == 0


int h, w;

char c[51][51];


void out() {
    cout << endl; rep(k, h) {rep(l, w) cout << c[k][l] << " "; cout << endl; }
}

bool not_reach_to_goal() {
    //たどり着けない判定
    queue<pii> q;
    q.push(pii(0, 0));
    
    int reached[h][w]; rep(i, h) rep(j, w) reached[i][j] = 0;
    
    int dy[4] = {0, 1, 0, -1}; //左、下、右、上
    int dx[4] = {-1, 0, 1, 0};
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        //cout << y << " " << x << endl;
        
        q.pop();
        rep(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (c[ny][nx] == '#') continue;
            if (reached[ny][nx]) continue;
            reached[ny][nx] = 1;
            q.push(pii(ny, nx));
        }
    }
    
    //cout << endl; rep(k, h) {rep(l, w) cout << reached[k][l] << " "; cout << endl; }
    
    
    if (reached[h - 1][0] == 0 || reached[0][w - 1] == 0 || reached[h - 1][w - 1] == 0) {
        cout << "NO" << endl;
        return 0;
    }
    return 1;
}


int di[4] = {0, -1, 0, 1}; //右、上、左、下
int dj[4] = {1, 0, -1, 0};
int reached[51][51];
bool move(int y, int x, int gy, int gx, int key) {
    
    if (y == gy && x == gx) return 1;
    
    int ret = 0;
    rep(i, 4) {
        
        int nxt = (key - 1 + i + 4) % 4;
        
        int ny = y + di[nxt];
        int nx = x + dj[nxt];
        
        if (reached[ny][nx]) continue;
        
        if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        if (c[ny][nx] == '#') continue;
        
        //if (ny >= h - 4 && x <= 2) {cout << ny << " " << nx << endl; out();}
        
        reached[ny][nx] = 1;
        c[ny][nx] = '#';
        ret |= move(ny, nx, gy, gx, nxt);
        
        if (ret == 0) c[ny][nx] = '.';
        else return ret;
    }
    
    return ret;
}
int main() {
    //cast caution
    //look constraints always
    cin.tie(0); ios::sync_with_stdio(false);
    
    
    while (cin >> h && h) {
        cin >> w;
        
        rep(i, h) rep(j, w) cin >> c[i][j];
        
        
        //out();
        
        if (not_reach_to_goal() == 0) continue;
        
        int end_flg = 0;
        
        
        //dx, dy最初に決め打ちしたらだめ
        //各マスで優先順位違う
        rep(i, h) rep(j, w) reached[i][j] = 0;
        reached[0][0] = 1;
        if (move(0, 0, h - 1, 0, 3) == 0) end_flg = 1;
        //out();
        //cout << endl; rep(i, h) {rep(j, w) cout << reached[i][j] << " "; cout << endl;}
        
        
        rep(i, h) rep(j, w) reached[i][j] = 0;
        reached[h - 1][0] = 1;
        if (move(h - 1, 0, h - 1, w - 1, 0) == 0) end_flg = 2;
        
        //out();
        
        rep(i, h) rep(j, w) reached[i][j] = 0;
        reached[h - 1][w - 1] = 1;
        if (move(h - 1, w - 1, 0, w - 1, 1) == 0) end_flg = 3;
        
        
        rep(i, h) rep(j, w) reached[i][j] = 0;
        reached[0][w - 1] = 1;
        if (move(0, w - 1, 0, 0, 2) == 0) end_flg = 4;
        
        //out();
        
        if (end_flg != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

