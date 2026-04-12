#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)n; ++i)
typedef pair<int,int> pii;

const int inf = 1<<29;
int r,c,m;
string room[51];
int on[51][51],off[51][51],con[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool in(int y,int x) {
    if(x < 0 || x >= c) return false;
    if(y < 0 || y >= r) return false;
    if(room[y][x] == '#') return false;
    return true;
}

vector<pii> bfs(int sy,int sx,int gy,int gx) {
    int dist[51][51];
    rep(i,r) rep(j,c) dist[i][j] = -1;
    dist[sy][sx] = 0;
    queue<pii> q; q.push(make_pair(sy,sx));

    while(!q.empty()) {
        pii p = q.front(); q.pop();
        for(int k=0; k<4; ++k) {
            int nx = p.second+dx[k],ny = p.first+dy[k];
            if(!in(ny,nx) || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[p.first][p.second]+1;
            q.push(make_pair(ny,nx));
        }
    }

    vector<pii> ret;
    int r = dist[gy][gx],x = gx,y = gy;
    while(true) {
        if(x == sx && y == sy) break;
        ret.push_back(make_pair(y,x));
        for(int k=0; k<4; ++k) {
            int nx = x+dx[k],ny = y+dy[k];
            if(!in(ny,nx) || dist[ny][nx]+1 != dist[y][x]) continue;
            x = nx,y = ny;
            break;
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    cin>>r>>c>>m;
    rep(i,r) cin>>room[i];

    rep(i,r) rep(j,c) cin>>con[i][j];
    rep(i,r) rep(j,c) cin>>on[i][j];
    rep(i,r) rep(j,c) cin>>off[i][j];

    vector<pii> root;
    int a,b,x,y;
    cin>>a>>b;
    root.push_back(make_pair(a,b));
    rep(i,m-1) {
        cin>>x>>y;
        vector<pii> r = bfs(a,b,x,y);
        for(int j=0; j<r.size(); ++j)
            root.push_back(r[j]);
        a=x,b=y;
    }

    vector<int> app[r*c];
    rep(i,r) rep(j,c) app[i*c+j].clear();

    rep(i,root.size()) {
        int y = root[i].first,x = root[i].second;
        app[y*c+x].push_back(i);
    }

    int ans = 0;
    rep(i,r) rep(j,c) {
        vector<int> &v = app[i*c+j];
        if(!v.empty()) ans += on[i][j];
        for(int k=1; k<v.size(); ++k)
            ans += min((v[k]-v[k-1])*con[i][j],on[i][j]+off[i][j]);
        if(!v.empty()) ans += off[i][j];
    }
    cout<<ans<<endl;
}