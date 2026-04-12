#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define repeq(i,a,b) for(int i=a;i<=(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const ll MOD=1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s,t;
    cin >> n >> m >> s >> t;
    --s, --t;
    vector<vector<pair<int,ll>>> g(n);
    rep(i,0,m) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].emplace_back(v,c);
        g[v].emplace_back(u,c);
    }
    const ll INFTY=LLONG_MAX;
    vector<ll> dist(n,INFTY);
    priority_queue<tuple<ll,int,int>> qu;
    qu.emplace(0,s,-1);
    vector<vi> backs(n);
    vi ord;
    while(!qu.empty()) {
        int u, pr;
        ll d;
        tie(d,u,pr) = qu.top();
        qu.pop();
        d=-d;
        if(d<dist[u]) {
            backs[u].push_back(pr);
            ord.push_back(u);
            dist[u]=d;
            for(auto e:g[u]) {
                qu.emplace(-d-e.second,e.first,u);
            }
        }
        else if(d==dist[u]) {
            backs[u].push_back(pr);
        }
    }
    vector<ll> posr(n,0);
    vector<bool> relev(n);
    posr[t]=1;
    relev[t]=true;
    assert(sz(ord)==n);
    for(int i=n-1;i>=0;--i) {
        int u = ord[i];
        if(!relev[u]) continue;
        for(auto v:backs[u]) {
            if(v!=-1) {
                posr[v]=(posr[v]+posr[u])%MOD;
                relev[v]=true;
            }
        }
    }
    vector<ll> posl(n,0);
    posl[s]=1;
    rep(i,0,n) {
        int u=ord[i];
        if(!relev[u]) continue;
        for(auto v:backs[u]) {
            if(v==-1 || !relev[v]) continue;
            posl[u] = (posl[u]+posl[v])%MOD;
        }
    }
    ll tot=posr[s], ans=0;
    //debug(tot);
    ll time=dist[t];
    rep(u,0,n) {
        if(!relev[u]) continue;
        if(dist[u]*2==time) {
            ll x = (posl[u]*posr[u])%MOD;
            ans=(ans+(x*(tot-x+MOD)%MOD)%MOD)%MOD;
        }
        for(auto e:g[u]) {
            int v=e.first;
            if(!relev[v] || dist[v]!=dist[u]+e.second) continue;
            if(2*dist[u]<time && time<2*dist[v]) {
                ll x = (posl[u]*posr[v])%MOD;
                ans=(ans+(x*(tot-x+MOD)%MOD)%MOD)%MOD;
            }
        }
    }
    cout<<ans<<endl;
}
