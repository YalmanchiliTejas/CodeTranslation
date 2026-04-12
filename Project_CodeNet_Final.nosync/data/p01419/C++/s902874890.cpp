#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long int lli;
#define REP(i, e) for(int (i)=1; (i)<=(e); (i)++)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool dfs(int y, int x, int gy, int gx, vector<int> &ry, vector<int> &rx, vector<vector<bool> > &used, vector<vector<char> > &field){
    if(field[y][x] == '#' || used[y][x]) return false;
    used[y][x] = true;
    if(y==gy && x==gx){
        ry.push_back(y);
        rx.push_back(x);
        return true;
    }
    for(int i=0; i<4; i++){
        if(dfs(y+dy[i], x+dx[i], gy, gx, ry, rx, used, field)){
            ry.push_back(y);
            rx.push_back(x);
            return true;
        }
    }
    return false;
}

int main(){
    int r,c,m;
    cin >> r >> c >> m;
    vector<vector<char> > field(r+2, vector<char>(c+2, '#'));
    vector<vector<lli> > on, off, keep(r+2, vector<lli>(c+2));
    on = off = keep;
    REP(i, r) REP(j, c) cin >> field[i][j];
    REP(i, r) REP(j, c) cin >> keep[i][j];
    REP(i, r) REP(j, c) cin >> on[i][j];
    REP(i, r) REP(j, c) cin >> off[i][j];
    vector<int> tx(m), ty(m);
    for(int i=0; i<m; i++){
        cin >> ty[i] >> tx[i];
        ty[i]++; tx[i]++;
    }

    vector<vector<vector<int> > > his(r+2, vector<vector<int> >(c+2));
    int time=0;
    for(int i=0; i<m-1; i++){
        vector<int> rx, ry;
        vector<vector<bool> > used(r+2, vector<bool>(c+2, false));
        dfs(ty[i+1], tx[i+1], ty[i], tx[i], ry, rx, used, field);
        int e = (i==m-2)? rx.size() : rx.size()-1;
        for(int j=0; j<e; j++){
            his[ry[j]][rx[j]].push_back(time+j);
        }
        time += e;
    }

    lli ans=0;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(!his[i][j].empty()){
                ans += on[i][j] + off[i][j];
            }
            for(int k=0; k<(int)his[i][j].size()-1; k++){
                ans += min((his[i][j][k+1]- his[i][j][k])*keep[i][j], off[i][j] +on[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

