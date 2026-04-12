#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

int n,m;
int s,t;
const ll mod = 1000000007;
const ll inf = 10000000000000000;
vector<pil> E[101010];

ll ds[101010];
ll dt[101010];

ll cs[101010];
ll ct[101010];

void dijkstra(int s, ll *d, ll *c){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    fill(d, d+n+1, inf);
    d[s] = 0;
    c[s] = 1;
    pq.emplace(0,s);
    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        if (d[p.second] < p.first)continue;
        for(auto e : E[p.second]){
            if (d[e.first] + e.second == d[p.second]){
                c[p.second] += c[e.first];
                c[p.second] %= mod;
            }
            if (d[p.second] + e.second < d[e.first]){
                d[e.first] = d[p.second] + e.second;
                pq.emplace(d[e.first], e.first);
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);

    for(int i=0;i<m;i++){
        int u,v;
        ll d;
        scanf("%d%d%lld",&u,&v,&d);
        E[u].emplace_back(v,d);
        E[v].emplace_back(u,d);
    }

    dijkstra(s,ds,cs);
    dijkstra(t,dt,ct);

    ll ans = cs[t] * cs[t] % mod;
    ll shortest = ds[t];

    for(int i=1;i<=n;i++){
        if (ds[i] == dt[i] && ds[i] + dt[i] == shortest){
            ans -= cs[i] * ct[i] % mod * ct[i] % mod * cs[i] % mod;
            ans = (ans+mod)%mod;
        }
    }

    for(int u=1;u<=n;u++){
        for(auto e : E[u]){
            int v = e.first;
            ll d = e.second;
            if (ds[u] + dt[v] + d == shortest && ds[u]*2 < shortest && dt[v]*2 < shortest){
                ans -= cs[u] * ct[v] % mod * ct[v] % mod * cs[u] % mod;
                ans = (ans+mod)%mod;
            }
        }
    }

    printf("%lld\n", ans);
}
