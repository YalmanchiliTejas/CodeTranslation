#include<bits/stdc++.h>
using namespace std;
using Weight=long long;
using ll=long long;

struct Edge{
    int from,to;
    Weight weight;
};
using Edges=vector<Edge>;
using Graph=vector<Edges>;

const ll MOD=1e9+7;
pair<vector<Weight>,vector<ll>> dijkstra(Graph& g,int s){
    const Weight INF=1e15;
    vector<Weight> d(g.size(),INF);
    d[s]=0;
    vector<ll> pat(g.size(),0);
    pat[s]=1;
    priority_queue<pair<Weight,int>,vector<pair<Weight,int>>,greater<>> que;
    que.push(make_pair(Weight(0),s));
    while(!que.empty()){
        Weight w=que.top().first;
        int v=que.top().second;
        que.pop();
        if(d[v]<w) continue;
        for(int i=0;i<g[v].size();i++){
            int to=g[v][i].to;
            if(d[to]==d[v]+g[v][i].weight){
                pat[to]+=pat[v];
                pat[to]%=MOD;
                continue;
            }
            if(d[to]<d[v]+g[v][i].weight) continue;
            pat[to]=pat[v];
            d[to]=d[v]+g[v][i].weight;
            que.push(make_pair(d[to],to));
        }
    }
    return make_pair(d,pat);
}

int main(){
    int n,m;
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    s--,t--;
    Graph g(n);
    for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        g[u].push_back(Edge{u,v,d});
        g[v].push_back(Edge{v,u,d});
    }
    auto rets=dijkstra(g,s);
    auto rett=dijkstra(g,t);
    auto ds=rets.first;
    auto dt=rett.first;
    auto pats=rets.second;
    auto patt=rett.second;
    Weight dist=ds[t];
    vector<ll> online(n,0);
    for(int i=0;i<n;i++){
        online[i]=(ds[i]+dt[i]==dist);
    }
    vector<ll> clash;
    for(int i=0;i<n;i++){
        if(online[i] && dist==ds[i]*2) clash.push_back((pats[i]*patt[i])%MOD);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            int fr=g[i][j].from;
            int to=g[i][j].to;
            if(online[fr] && online[to] && ds[fr]+g[i][j].weight==ds[to]){
                if(ds[fr]*2<dist && dt[to]*2<dist){
                    clash.push_back((pats[fr]*patt[to])%MOD);
                }
            }
        }
    }
    ll sum=accumulate(clash.begin(),clash.end(),0LL)%MOD;
    ll sqsum=(accumulate(clash.begin(),clash.end(),0LL,[](ll a,ll b){return (a+(b*b)%MOD)%MOD;}));
    cout<<(sum*sum-sqsum+MOD)%MOD<<endl;
    return 0;
}