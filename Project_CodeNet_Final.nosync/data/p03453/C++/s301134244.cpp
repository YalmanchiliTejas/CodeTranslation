#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

vector<ll> dijkstra(const vector<vector<pair<int,int>>> &graph,int s,vector<ll> &cnt){
    int n=(int)graph.size();
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    vector<ll> dist(n,linf);
    dist[s]=0;
    cnt.assign(n,0);
    cnt[s]=1;
    pq.push({0,s});
    while(pq.size()){
        auto p=pq.top();
        pq.pop();
        int v=p.second;
        if(dist[v]<p.first)continue;
        for(auto edge:graph[v]){
            int u=edge.first;
            int w=edge.second;
            if(dist[v]+w<dist[u]){
                dist[u]=dist[v]+w;
                cnt[u]=cnt[v];
                pq.push({dist[u],u});
            }
            else if(dist[v]+w==dist[u]){
                cnt[u]=(cnt[u]+cnt[v])%mod;
            }
        }
    }
    return dist;
}

int main(){
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    --s,--t;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        --a,--b;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    vector<ll> cnt_t,cnt_a;
    vector<ll> d_t=dijkstra(g,s,cnt_t);
    vector<ll> d_a=dijkstra(g,t,cnt_a);
    vector<ll> path;
    rep(i,n){
        if(d_t[i]==d_a[i]&&d_t[i]+d_a[i]==d_t[t]){
            path.push_back((cnt_t[i]*cnt_a[i])%mod);
        }
        rep(j,g[i].size()){
            ll w=g[i][j].second;
            int to=g[i][j].first;
            if(d_t[i]+w+d_a[to]!=d_t[t])continue;
            if(d_t[i]<d_a[i]&&d_t[to]>d_a[to]){
                path.push_back((cnt_t[i]*cnt_a[to])%mod);
            }
        }
    }
    ll ans=(cnt_t[t]*cnt_t[t])%mod;
    for(ll e:path){
        ans=(ans-e*e)%mod;
    }
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
}
