#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

const int VMAX=100100;
int V,E;
vector<vector<pair<int,int>>> edge;
bool used[VMAX];
long long MST(int start){
    if(V==1) return 0;
    rep(i,VMAX) used[i]=0;
    // {cost,{from,to}}
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(auto e:edge[start]){
        pq.push({e.second,{start,e.first}});
    }
    long long ret=0;
    int cnt=1;
    while(pq.size()||cnt<V){
        auto e=pq.top(); pq.pop();
        int cost=e.first,from=e.second.first,to=e.second.second;
        used[from]=1;
        if(!used[to]){
            ret+=cost;
            used[to]=1;
            cnt++;
            for(auto e:edge[to]){
                pq.push({e.second,{to,e.first}});
            }
        }
    }
    return (cnt==V?ret:-1);
}
int main(){
    cin>>V;
    pair<pair<int,int>,int> vx[V],vy[V];
    rep(i,V){
        int x,y; cin>>x>>y;
        vx[i]={{x,y},i};
        vy[i]={{y,x},i};
    }
    sort(vx,vx+V); sort(vy,vy+V);
    edge.resize(V);
    rep(i,V-1){
        int from=vx[i].second,to=vx[i+1].second,cost=abs(vx[i].first.first-vx[i+1].first.first);
        edge[from].push_back({to,cost});
        edge[to].push_back({from,cost});
        from=vy[i].second,to=vy[i+1].second,cost=abs(vy[i].first.first-vy[i+1].first.first);
        edge[from].push_back({to,cost});
        edge[to].push_back({from,cost});
    }
    cout<<MST(0)<<endl;
    return 0;
}
