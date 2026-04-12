#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

vecveci seen(10,veci(10));
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int H,W;
bool ok = true;

void dfs(vector<string> &G, int y, int x) {
    seen[y][x] = 1;
    bool go = false;
    REP(dir,4) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
        if(seen[ny][nx] || G[ny][nx] == '.') continue;
        if(dir == 0 || dir == 1) ok = false;
        go = true;
        //cout << y << "->" << ny << " " << x << "->" << nx << endl;
        dfs(G,ny,nx);
    }
    //cout << y << " " << x << " " << go << endl;
    if(!go) {
        if(y < H-1 || x < W-1) ok = false;
    }
}

int main() {
    cin >> H >> W;
    vector<string> G(H);
    REP(i,H) cin >> G[i];
    dfs(G,0,0);
    cout << (ok ? "Possible" : "Impossible") << endl; 
}