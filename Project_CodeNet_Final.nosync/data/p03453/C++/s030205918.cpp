#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=1000000000000000010;
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,1,-1,0,1,-1,0};
struct edge{int to;ll cost;};
vector<edge> G[100010];
vector<int> DAG1[100010],DAG2[100010];
vector<ll> d1,d2;
vector<int> a1,a2;
int u[200010],v[200010],d[200010],h1[100010],h2[100010];
ll dp1[100010],dp2[100010];
bool f[200010],v1[100010],v2[100010],ff[100010];
vector<ll> dijkstra(int s,vector<edge> g[]){
    vector<ll> d(100000,LINF);
    priority_queue<P,vector<P>,greater<P>> q;
    d[s]=0;
    q.push(P(0,s));
    while(!q.empty()){
        P p=q.top();q.pop();
        int v=p.second;
        for(int i=0;i<g[v].size();i++){
            edge e=g[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                q.push(P(d[e.to],e.to));
            }
        }
    }
    return d;
}
int main(){
    int n,m;cin>>n>>m;
    int s,t;cin>>s>>t;s--;t--;
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>d[i];u[i]--;v[i]--;
        G[u[i]].push_back({v[i],d[i]});
        G[v[i]].push_back({u[i],d[i]});
    }
    d1=dijkstra(s,G);
    d2=dijkstra(t,G);
    for(int i=0;i<m;i++){
        if(d1[u[i]]+d[i]==d1[v[i]]&&d1[u[i]]+d[i]+d2[v[i]]==d1[t]){
            f[i]=true;
            ff[u[i]]=true;
            ff[v[i]]=true;
            DAG1[u[i]].push_back(v[i]);
            DAG2[v[i]].push_back(u[i]);
            h1[v[i]]++;
            h2[u[i]]++;
        }else if(d2[u[i]]+d[i]==d2[v[i]]&&d2[u[i]]+d[i]+d1[v[i]]==d2[s]){
            f[i]=true;
            ff[u[i]]=true;
            ff[v[i]]=true;
            DAG2[u[i]].push_back(v[i]);
            DAG1[v[i]].push_back(u[i]);
            h1[u[i]]++;
            h2[v[i]]++;
        }
    }
    dp1[s]=1;
    dp2[t]=1;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!h1[i]&&ff[i])st.push(i);
    }
    while(!st.empty()){
        int id=st.top();
        st.pop();
        a1.push_back(id);
        for(auto e:DAG1[id]){
            h1[e]--;
            if(!h1[e])st.push(e);
        }
    }
    for(int i=0;i<n;i++){
        if(!h2[i]&&ff[i])st.push(i);
    }
    while(!st.empty()){
        int id=st.top();
        st.pop();
        a2.push_back(id);
        for(auto e:DAG2[id]){
            h2[e]--;
            if(!h2[e])st.push(e);
        }
    }
    for(int i=0;i<a1.size();i++){
        int v=a1[i];
        for(int j=0;j<DAG1[v].size();j++){
            int e=DAG1[v][j];
            (dp1[e]+=dp1[v])%=MOD;
        }
    }
    for(int i=0;i<a2.size();i++){
        int v=a2[i];
        for(int j=0;j<DAG2[v].size();j++){
            int e=DAG2[v][j];
            (dp2[e]+=dp2[v])%=MOD;
        }
    }
    ll ans=(dp1[t]*dp2[s])%MOD;
    for(int i=0;i<n;i++){
        if(d1[i]==d2[i]){
            ans=(ans+MOD-(dp1[i]*dp1[i]%MOD)*(dp2[i]*dp2[i]%MOD)%MOD)%MOD;
        }
    }
    double dd=(double)d1[t]/2;
    for(int i=0;i<m;i++){
        if(!f[i])continue;
        if((double)d1[u[i]]<dd&&(double)d1[v[i]]>dd){
            ans=(ans+MOD-(dp1[u[i]]*dp1[u[i]]%MOD)*(dp2[v[i]]*dp2[v[i]]%MOD)%MOD)%MOD;
        }else if((double)d2[u[i]]<dd&&(double)d2[v[i]]>dd){
            ans=(ans+MOD-(dp2[u[i]]*dp2[u[i]]%MOD)*(dp1[v[i]]*dp1[v[i]]%MOD)%MOD)%MOD;
        }
    }
    cout<<ans<<endl;
}
