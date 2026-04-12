#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];
#define int long long

int H, W;
int dx[2] = {0,1};
int dy[2] = {1,0};
vector<vector<bool>> checked(8,vector<bool>(8,false));
vector<string> fmap(8);

int roads = 0;

bool dfs(int x, int y, int distance){
    if((x < 0 || W <= x)||(y < 0 || H <= y)) return false;
    if(checked[y][x]) return false;
    if(fmap[y][x]=='.') return false;
    
    if(x==W-1 && y==H-1 && distance==roads) return true;
    
    checked[y][x] = true;
    rep(i,2) if(dfs(x+dx[i], y+dy[i], distance+1)) return true;
    return false;
}

signed main(){
    cin >> H >> W;
    collect(fmap, H);
    rep(x,W)rep(y,H){
        if(fmap[y][x]=='#') roads++;
    }
    cout << (dfs(0,0,1) ? "Possible" : "Impossible") << endl;
    return 0;
}