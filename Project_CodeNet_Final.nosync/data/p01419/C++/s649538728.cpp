#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

bool vis[51][51];
int r,c;
vector<string> s(51);
vector<vector<vector<int>>> d(51,vector<vector<int>> (51));

int dfs(int y,int x,int gy,int gx,int tt){
    if(y==gy&&x==gx) return tt;
    if(vis[y][x]) return -1;
    vis[y][x] = true;
    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k], nx = x + dx[k];
        if(0<=ny&&ny<r&&0<=nx&&nx<c&&s[ny][nx]=='.'){
            auto ret = dfs(ny,nx,gy,gx,tt+1);
            if(ret>=0){
                d[ny][nx].pb(tt+1);
                return ret;
            }
        }
    }
    return -1;
};



int main(){
    int m;cin >> r >> c >> m;
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }
    vector<vector<int>> a(r,vector<int> (c,0));
    auto oc = a, fc = a;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> oc[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> fc[i][j];
        }
    }
    vector<P> v(m,mp(0,0));
    for (int i = 0; i < m; i++) {
        cin >> v[i].fs >> v[i].sc;
    }
    int t = 0;
    d[v[0].fs][v[0].sc].pb(0);
    for (int i = 1; i < v.size(); i++) {
        memset(vis,false,sizeof(vis));
        auto q = dfs(v[i-1].fs,v[i-1].sc,v[i].fs,v[i].sc,t);
        t = q;
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(d[i][j].size()){
                int p = oc[i][j] + fc[i][j];
                ans += p;
                for (int k = 1; k < d[i][j].size(); k++) {
                    ans += min(p,a[i][j] * (d[i][j][k] - d[i][j][k-1]));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}


