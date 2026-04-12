#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main(){
    int r,c,m;
    cin>>r>>c>>m;
    vector<string> f(r);
    for(int i=0;i<r;i++) cin>>f[i];
    vector<vector<ll>> keep(r,vector<ll>(c,0));
    vector<vector<ll>> turn(r,vector<ll>(c,0));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>keep[i][j];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        ll tmp; cin>>tmp;
        turn[i][j]+=tmp;
    }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        ll tmp; cin>>tmp;
        turn[i][j]+=tmp;
    }
    vector<pair<int,int>> task(m);
    for(int i=0;i<m;i++) cin>>task[i].first>>task[i].second;

    auto isBlank=[&](int x,int y){
        return 0<=x && x<r && 0<=y && y<c && f[x][y]=='.';
    };
    function<bool(int,int,int,int,int,int,stack<pair<int,int>>&)> getPath=
    [&](int x,int y,int tx,int ty,int px,int py,stack<pair<int,int>> &st){
        if(!isBlank(x,y)) return false;
        if(x==tx && y==ty) return true;
        for(int i=0;i<4;i++){
            if(x+dx[i]==px && y+dy[i]==py) continue;
            if(getPath(x+dx[i],y+dy[i],tx,ty,x,y,st)){
                st.push({x,y});
                return true;
            }
        }
        return false;
    };
    ll t=0;
    vector<vector<ll>> prev(r,vector<ll>(c,-1));
    auto getCost=[&](int x,int y){
        ll ret=prev[x][y]==-1 ? turn[x][y] : min(turn[x][y],(t-prev[x][y])*keep[x][y]);
        prev[x][y]=t++;
        return ret;
    };
    ll res=0;
    for(int i=0;i+1<m;i++){
        int sx=task[i].first,sy=task[i].second;
        int tx=task[i+1].first,ty=task[i+1].second;
        stack<pair<int,int>> path;
        getPath(sx,sy,tx,ty,-1,-1,path);
        while(!path.empty()){
            auto tmp=path.top(); path.pop();
            res+=getCost(tmp.first,tmp.second);
        }
    }
    res+=getCost(task.back().first,task.back().second);
    cout<<res<<endl;
    return 0;
}
