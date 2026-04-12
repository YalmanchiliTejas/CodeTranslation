#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <ll, int> P;
const ll MOD=1e9+7;
const int MAX_V=100000;
const ll INF=1e17;
struct edge {int to; ll cost;};
int V, M, S,T;
vector <edge> G[MAX_V];
ll d[2][MAX_V], n[2][MAX_V];
void dijkstra (int s, int k){
    priority_queue<P, vector<P>, greater<P>> que;
    auto itr=d[k];
    fill(itr,itr+V,INF);
    itr[s]=0;
    que.push(P(0,s));
    while (!que.empty()) {
        P p=que.top();  que.pop();
        int v=p.second;
        if (itr[v]<p.first) continue;
        rep(i,0,G[v].size()){
            edge e=G[v][i];
            if (itr[e.to]>itr[v]+e.cost){
                itr[e.to]=itr[v]+e.cost;
                que.push(P(itr[e.to], e.to));
            }
        }
    }
}

void dfs(int s, int k){
    priority_queue<P, vector<P>, greater<P>> que;
    auto dd=d[k];
    rep(i,0,V) que.push(P(dd[i], i));
    auto N=n[k];
    N[s]=1;
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        rep(i,0,G[v].size()){
            edge e=G[v][i];
            if (dd[e.to]==dd[v]+e.cost){
                N[e.to]+=N[v];
                N[e.to]%=MOD;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>V>>M>>S>>T;
    S--; T--;
    rep(i,0,M){
        int u,v; ll D;
        cin>>u>>v>>D;
        u--; v--;
        G[u].pb(edge{v,D});
        G[v].pb(edge{u,D});
    }
    dijkstra(S,0); dijkstra(T, 1);
    dfs(S,0); dfs(T,1);
    ll D=d[0][T];
    ll ans=n[0][T]*n[0][T]%MOD;
    rep(i,0,V){
        if(d[0][i]*2==D&&d[1][i]*2==D){
            ans-=n[0][i]*n[0][i]%MOD*n[1][i]%MOD*n[1][i]%MOD;
            if(ans<0) ans+=MOD;
        }
    }
    rep(i,0,V){
        for(auto &e : G[i]){
            if(d[0][i]+e.cost+d[1][e.to]==D&&d[0][i]*2<D&&d[1][e.to]*2<D){
                ans-=n[0][i]*n[0][i]%MOD*n[1][e.to]%MOD*n[1][e.to]%MOD;
                if(ans<0) ans+=MOD;
            }
        }
    }
    cout <<ans<<"\n";
}