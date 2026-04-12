#include<bits/stdc++.h>
using namespace std;

using Weight=long long;
using ll=long long;
const ll MOD=1e9+7;
struct Edge{
    int to;
    Weight weight;
};
using Edges=vector<Edge>;
using Graph=vector<Edges>;

Weight INF=1e15+7;
vector<Weight> Dijkstra(int s,const Graph& g){
    int n=g.size();
    vector<Weight> res(n,INF);
    vector<int> used(n,0);
    res[s]=0;
    priority_queue<pair<Weight,int>,vector<pair<Weight,int>>,greater<>> que;
    que.push(make_pair(Weight(0),s));
    while(!que.empty()){
        auto p=que.top(); que.pop();
        Weight dist=p.first;
        int v=p.second;
        if(used[v]) continue;
        used[v]=true;
        for(int i=0;i<g[v].size();i++){
            Weight tdist=dist+g[v][i].weight;
            if(tdist<res[g[v][i].to]){
                res[g[v][i].to]=tdist;
                que.push(make_pair(tdist,g[v][i].to));
            }
        }
    }
    return res;
}



int main(){
    int n,m;
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    s--,t--;
    Graph g(n);
    for(int i=0;i<m;i++){
        int u,v;
        Weight d;
        cin>>u>>v>>d;
        u--,v--;
        g[u].push_back(Edge{v,d});
        g[v].push_back(Edge{u,d});
    }
    auto d=Dijkstra(s,g);
    vector<int> need(n,false);
    queue<int> que;
    que.push(t);
    need[t]=true;
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(int i=0;i<g[v].size();i++){
            int from=g[v][i].to;
            Weight cost=g[v][i].weight;
            if(!need[from] && d[from]+cost==d[v]){
                need[from]=true;
                que.push(from);
            }
        }
    }
    
    vector<ll> pat(n,0);
    pat[s]=1;
    priority_queue<pair<Weight,int>> que2;
    for(int i=0;i<n;i++){
        if(need[i]){
            que2.push(make_pair(-d[i],i));
        }
    }
    while(!que2.empty()){
        int v=que2.top().second;
        
        que2.pop();
        for(int i=0;i<g[v].size();i++){
            if(d[v]+g[v][i].weight!=d[g[v][i].to]) continue;
            pat[g[v][i].to]+=pat[v];
            pat[g[v][i].to]%=MOD;   
        }
    }
    vector<ll> pat2(n,0);
    pat2[t]=1;
    for(int i=0;i<n;i++){
        if(need[i]){
            que2.push(make_pair(d[i],i));
        }
    }
    while(!que2.empty()){
        int v=que2.top().second;
        que2.pop();
        for(int i=0;i<g[v].size();i++){
            if(d[v]-g[v][i].weight!=d[g[v][i].to]) continue;
            pat2[g[v][i].to]+=pat2[v];
            pat2[g[v][i].to]%=MOD;   
        }
    }

    


    bool dochu=d[t]%2;
    vector<ll> pats;
    vector<ll> patt;
    for(int i=0;i<n;i++){
        if(need[i]){
            if(d[i]>d[t]/2) continue;
            if(!dochu && d[i]==d[t]/2){
                pats.push_back((pat[i]*pat2[i])%MOD);
                patt.push_back((pat2[i]*pat[i])%MOD);
            }
            else{
                for(int j=0;j<g[i].size();j++){
                    int to=g[i][j].to;
                    Weight cost=g[i][j].weight;
                    if(!need[to]) continue;
                    if(d[to]!=d[i]+cost) continue;
                    if(d[t]/2<d[i]+cost){
                        pats.push_back((pat[i]*pat2[to])%MOD);
                        patt.push_back((pat2[to]*pat[i])%MOD);
                    }
                }
            }
        }
    }

    ll sums=accumulate(pats.begin(),pats.end(),0LL);
    ll sumt=accumulate(patt.begin(),patt.end(),0LL);
    sums%=MOD;
    sumt%=MOD;
    ll sqsum=0;
    for(int i=0;i<pats.size();i++){
        sqsum+=pats[i]*patt[i];
        sqsum%=MOD;
    }
    ll res=(sums*sumt)%MOD-sqsum;
    res%=MOD;
    res+=MOD;
    res%=MOD;
    cout<<res<<endl;
    return 0;
}