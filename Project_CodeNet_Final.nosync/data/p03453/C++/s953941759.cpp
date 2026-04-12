#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1E5+2;
const int MOD = 1e9+7;

int n, m;
int s, t;

vector<pair<int, int> > g[MAXN];
vector<int> ds(MAXN, -1), dt(MAXN, -1), cnts(MAXN, 0), cntt(MAXN, 0);

priority_queue<pair<int, int> > pq;

void SP(int src, vector<int>& dist, vector<int>& cnt){
    dist[src] = 0; cnt[src] = 1;
    pq.push({0, src});
    while(!pq.empty()){
        int d = -pq.top().first,  u= pq.top().second; pq.pop();
        if(d > dist[u]) continue;
        for(pair<int, int> coup : g[u]){
            int v = coup.first, w = coup.second;
            if(dist[v] == -1 || (dist[v] > dist[u]+w)){
                dist[v] = dist[u]+w;
                cnt[v] = cnt[u];
                pq.push({-dist[v], v});
            }
            else if(dist[v] == dist[u]+w){
                cnt[v] += cnt[u];
                cnt[v] %= MOD;
            }
        }
    }
}

signed main()
{
		//freopen("input.txt", "r", stdin);
    cin >>n >> m;
    cin >> s >> t;
    for(int i=1;i <= m; ++i){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    SP(s, ds, cnts); SP(t, dt, cntt);
    int ans = (cnts[t]*cntt[s])%MOD;
    for(int u=1; u<= n; ++u){
        for(pair<int, int> v : g[u]){
            if(ds[u] + dt[v.first] + v.second == ds[t] && abs(ds[u] - dt[v.first]) < v.second){
                ans += MOD-(((cnts[u]*cntt[v.first])%MOD)*((cnts[u]*cntt[v.first])%MOD)%MOD);
                ans %= MOD;
            }
        }
        if(ds[u] + dt[u] == ds[t] && ds[u] == dt[u]){
            ans += MOD-(((cnts[u]*cntt[u])%MOD)*((cnts[u]*cntt[u])%MOD)%MOD);
            ans %= MOD;
        }
    }
    cout << ans;
}