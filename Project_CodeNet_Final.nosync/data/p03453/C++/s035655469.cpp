#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> li;
const int N = 100005;
const ll INF = 1e18;
const int mod = 1e9+7;
ll cs[N],ct[N],ds[N],dt[N];
vector<ii> adjlist[N];
int n,m,s,t;
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for (int i = 0; i < m; i++){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        adjlist[u].push_back(ii(v,d));
        adjlist[v].push_back(ii(u,d));
    }
    priority_queue<li,vector<li> ,greater<li> > pq;
    fill (ds,ds+n+1,INF);
    pq.push(li(0,s));
    ds[s] = 0;
    cs[s] = 1;
    while (pq.size()){
        li cur = pq.top();pq.pop();
        ll d = cur.first;
        int u = cur.second;
        if (ds[u] < d) continue;
        for (auto v : adjlist[u]){
            if (ds[v.first] > ds[u] + v.second){
                ds[v.first] = ds[u] + v.second;
                cs[v.first] = cs[u];
                pq.push(li(ds[v.first],v.first));
            }
            else if (ds[v.first] == ds[u]+v.second){
                cs[v.first] += cs[u];
                cs[v.first] %= mod;
            }
        }
    }
    fill (dt,dt+n+1,INF);
    pq.push(li(0ll,t));
    dt[t] = 0;
    ct[t] = 1;
    while (pq.size()){
        li cur = pq.top(); pq.pop();
        ll d = cur.first;
        int u =cur.second;
        if (dt[u] < d) continue;
        for (auto v : adjlist[u]){
            if (dt[v.first] > dt[u] + v.second){
                dt[v.first] = dt[u] + v.second;
                ct[v.first] = ct[u];
                pq.push(li(dt[v.first],v.first));
            }
            else if (dt[v.first] == dt[u]+v.second){
                ct[v.first] += ct[u];
                ct[v.first] %= mod;
            }
        }
    }
    ll ans = (cs[t] * ct[s]) % mod;
    ll total = ds[t];
    //printf("total ways: %lld^2, total distance %lld",cs[t],ds[t]);
    for (int i = 1; i <= n; i++){
        //printf("Vertex %d %lld %lld\n",i,cs[i],ct[i]);
        if (2*ds[i] == total && 2*dt[i] == total){
            //printf("Vertex %d cannot: %lld\n",i,cs[i]);
            ll num = (cs[i]*ct[i])%mod;
            num *= num; num %= mod;
            ans += mod-num; ans %= mod;
        }
        if (2*ds[i] < total){
            for (auto v : adjlist[i]){
                if (2*dt[v.first] < total && dt[v.first]+ds[i]+v.second == ds[t]){
                    //printf("Edge %d %d cannot (%lld -> %lld): %lld %lld\n",i,v.first,ds[i],dt[v.first],cs[i],ct[v.first]);
                    ll num = (cs[i]*ct[v.first])%mod;
                    num *= num; num %= mod;
                    ans += mod-num; ans %= mod;
                }
            }
        }
    }
    printf("%lld",ans);
}
