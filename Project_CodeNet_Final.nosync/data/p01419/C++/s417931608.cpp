#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

int R,C,M;
char Room[50][50];
int Cost[3][50][50];
pii TaskRoom[1001];
vector<int> Time[50][50];

int grid2ind(pii grid){
    return grid.first * C + grid.second;
}
pii ind2grid(int ind){
    return {ind/C,ind%C};
}

int d[4] = {1,0,-1,0};
int NowTime = 0;
int NextTime = -1;
bool visited[50][50];
bool check(int y,int x,int ty,int tx,int dep = 0){
    if(visited[y][x]) return false;
    visited[y][x] = true;
    if(y == ty && x == tx){
        NextTime = NowTime+dep;
        Time[y][x].push_back(NowTime+dep);
        return true;
    }
    
    for(int k = 0; k < 4;k++){
        int ny = y + d[k];
        int nx = x + d[k^1];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if(Room[ny][nx]=='#') continue;
        if(check(ny,nx,ty,tx,dep+1)){
            Time[y][x].push_back(NowTime+dep);
            return true;
        }
    }
    return false;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> R >> C >> M;
    for(int i = 0; i < R;i++){
        for(int j = 0; j < C;j++){
            cin >> Room[i][j];
        }
    }
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < R;j++){
            for(int k = 0; k < C;k++){
                cin >> Cost[i][j][k];
            }
        }
    }
    for(int i = 0; i < M;i++) cin >> TaskRoom[i].first >> TaskRoom[i].second;
    
    int py,px; tie(py,px) = TaskRoom[0];
    for(int i = 1; i < M;i++){
        fill(*visited,*visited+50*50,false);
        check(py,px,TaskRoom[i].first,TaskRoom[i].second);
        NowTime = NextTime;
        tie(py,px) = TaskRoom[i];
    }
    
    ll ans = 0;
    for(int i = 0; i < R;i++){
        for(int j = 0; j < C;j++){
            sort(Time[i][j].begin(),Time[i][j].end());
            
//            cout << "(" << i << "," << j << ")" << endl;
//            for(auto t:Time[i][j]) cout << t << " "; cout << endl;
            
            if(Time[i][j].empty()) continue;
            ans += Cost[1][i][j] + Cost[2][i][j];
            
            for(int k = 1; k < Time[i][j].size();k++){
                ll dt = Time[i][j][k] - Time[i][j][k-1];
                ans += min(dt*Cost[0][i][j],(ll)Cost[1][i][j] + Cost[2][i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

