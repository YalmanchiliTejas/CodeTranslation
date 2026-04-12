#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);
struct edge{ll to,cost;};

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

const int MAX_V=100010;

ll N,M,S,T;
vector<vector<edge>> G(MAX_V);
vector<ll> d(MAX_V,IINF),cnt(MAX_V,0);

void Dijkstra(int s){
    priority_queue<Pll,vector<Pll>,greater<Pll>> pq;
    d[s]=0;
    cnt[s]=1;
    pq.push(Pll(0,s));
    while(!pq.empty()){
        Pll p=pq.top();
        pq.pop();
        int v=p.second;
        if (d[v]<p.first) continue;
        for (auto e:G[v]){
            if (d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                pq.push(Pll(d[e.to],e.to));
                cnt[e.to]=cnt[v];
            }
            else if (d[e.to]==d[v]+e.cost) cnt[e.to]=(cnt[e.to]+cnt[v])%MOD;
        }
    }
}

int main(){
    cin >> N >> M >> S >> T;
    --S,--T;
    rep(i,M){
        ll u,v,d;
        cin >> u >> v >> d;
        --u,--v;
        G[u].push_back(edge{v,d});
        G[v].push_back(edge{u,d});
    }
    Dijkstra(S);
    vector<ll> ds=d,cnts=cnt;
    ll distance=d[T],all=cnt[T];
    rep(i,N) d[i]=IINF,cnt[i]=0;
    Dijkstra(T);
    vector<ll> dt=d,cntt=cnt;
    ll ans=all*all%MOD;
    rep(i,N){
        if (ds[i]+dt[i]==distance){
            if (ds[i]==dt[i]) ans=(ans-cnts[i]*cntt[i]%MOD*cntt[i]%MOD*cnts[i]%MOD+MOD)%MOD;
            else {
                for (auto e:G[i]){
                    ll t=e.to;
                    if (ds[t]+dt[t]!=distance||ds[i]+e.cost!=ds[t]) continue;
                    if (ds[i]*2<distance&&dt[t]*2<distance){
                        ans=(ans-cnts[i]*cntt[t]%MOD*cntt[t]%MOD*cnts[i]%MOD+MOD)%MOD;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}