#include <bits/stdc++.h>
typedef long long int ll;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define drep(i,n) for(ll i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (ll i = s; i < t; ++i)
using namespace std;
typedef pair<ll,ll> P;
#define yn {puts("Yes");}else{puts("No");}
struct edge{ ll to, cost; };
const ll INF = 1001001001001001001;
const int MAX_N = 200005;
const int MAX_V = 200005;
vector<edge> G[MAX_V];
ll d[MAX_V];
ll sum[MAX_V];
const ll MOD = 1000000007;

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+MAX_V, INF);
    rep(i,MAX_N) sum[i] = 0;
    d[s] = 0;
    sum[s] = 1;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v]<p.first) continue;
        for(int i=0; i<G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                sum[e.to] = sum[v];
                que.push(P(d[e.to], e.to));
            }else if(d[e.to] == d[v] + e.cost){
                sum[e.to] += sum[v];
                sum[e.to] %= MOD;
            }
        }
    }
}

ll ds[MAX_N], sums[MAX_N], dt[MAX_N], sumt[MAX_N];

int main() {
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    s--; t--;
    int u[m], v[m];
    ll w[m];
    rep(i,m){
        ll from,to,cost;
        cin >> from >> to >> cost;
        from--; to--;
        w[i] = cost;
        u[i] = from;
        v[i] = to;
        edge e1, e2;
        e1.to = to; e1.cost = cost;
        e2.to = from; e2.cost = cost;
        G[from].push_back(e1);
        G[to].push_back(e2);
    }

    dijkstra(s);
    rep(i,MAX_N){
        ds[i] = d[i];
        sums[i] = sum[i];
    }
    dijkstra(t);
    rep(i,MAX_N){
        dt[i] = d[i];
        sumt[i] = sum[i];
    }

    ll dist = ds[t];
    ll ans = sums[t] * sumt[s] % MOD;;

    // cout << dist << endl;

    // 頂点 
    if(dist % 2 == 0){
        ll half = dist / 2;
        rep(i,n){
            if(ds[i] == half && dt[i] == half){
                ans -= (sums[i] * sumt[i] % MOD) * (sums[i] * sumt[i] % MOD) % MOD;
                if(ans < 0)ans += MOD;
            }
        }
    }


    // 辺上
    rep(i,m){
        int x = u[i];
        int y = v[i];
        ll cost = w[i];
        if(ds[x]+dt[x]!=dist) continue;
        if(ds[y]+dt[y]!=dist) continue;
        if(abs(ds[x]-ds[y])!=cost) continue;
        if(abs(dt[x]-dt[y])!=cost) continue;
        if(ds[x] < ds[y]){
            if(ds[x] + cost + dt[y] != dist) continue;
        }else{
            if(ds[y] + cost + dt[x] != dist) continue; 
        }
        
        if(dist%2==0){
            ll half = dist / 2;
            if(ds[x]==half||ds[y]==half)continue;
        }
        // cout << i << ' ' << x << ' ' << y << ' ' << cost << endl;
        double half = (double)dist / 2;
        // cout << i << ' ' << half << endl;
        if((double)min(ds[x],ds[y])<half && half<(double)max(ds[x],ds[y])){
            if(ds[x] < ds[y]){
                ans -= (sums[x] * sumt[y] % MOD) * (sums[x] * sumt[y] % MOD) % MOD;
            }else{
                ans -= (sums[y] * sumt[x] % MOD) * (sums[y] * sumt[x] % MOD) % MOD;
            }
            if(ans < 0)ans += MOD;
        }
    }

    cout << ans << endl;
    return 0;
}

