#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long 
#define int long long 
#define PB push_back
#define FAST ios::sync_with_stdio(false);cin.tie(0)
	
const int maxn = 2e5 + 100 , INF = 1e18 , MOD = 1e9 + 7;

vector <pair <ll , ll> > edges[maxn];
set <pair <ll, ll> > s;
ll dist1[maxn] , dist2[maxn];
ll dp1[maxn] , dp2[maxn];


int32_t main() {
    ll total = 0;
    ll bad = 0;
    int n , m;
    int b , e;
    cin >> n >> m >> b >> e;
    b--; e--;
    for (int i = 0; i < m; ++i) {
        int x , y , z;
        cin >> x >> y >> z;
        x--; y--;
        edges[x].PB({y , z});
        edges[y].PB({x , z});
    }
    fill(dist1 , dist1 + maxn , INF);
    fill(dist2 , dist2 + maxn , INF);
    dist1[b] = 0; dist2[e] = 0;
    s.insert({0 , b});
    dp1[b] = 1; dp2[e] = 1;
    while(s.size()) {
        int v = s.begin() -> S;
        s.erase(s.begin());
        for (auto u : edges[v]) {
            if(dist1[u.F] > dist1[v] + u.S) {
                s.erase({dist1[u.F] , u.F});
                dist1[u.F] = dist1[v] + u.S;
                s.insert({dist1[u.F] , u.F});
                dp1[u.F] = 0;
            }
            if(dist1[u.F] == dist1[v] + u.S) {
                dp1[u.F] += dp1[v];
                dp1[u.F] %= MOD;
            } 
        }
    }
    s.insert({0 , e});
    while(s.size()) {
        int v = s.begin() -> S;
        s.erase(s.begin());
        for (auto u : edges[v]) {
            if(dist2[u.F] > dist2[v] + u.S) {
                s.erase({dist2[u.F] , u.F});
                dist2[u.F] = dist2[v] + u.S;
                s.insert({dist2[u.F] , u.F});
                dp2[u.F] = 0;
            }
            if(dist2[u.F] == dist2[v] + u.S) {
                dp2[u.F] += dp2[v];
                dp2[u.F] %= MOD;
            }
        }
    }
    total = 1ll * dp1[e] * dp1[e] % MOD;
    for (int i = 0; i < n; ++i) {
        if(dist1[i] + dist2[i] == dist1[e] && dist1[i] == dist2[i]) {
            bad = (bad + (1ll * dp1[i] * dp1[i] % MOD * dp2[i] % MOD * dp2[i])) % MOD;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto u : edges[i]) {
            int v = u.F;
            int w = u.S;
            if(dist1[i] + w + dist2[v] == dist1[e] && w + dist1[i] > dist2[v] && dist1[i] < dist2[v] + w) {
                bad = (bad + (1ll * dp1[i] * dp1[i] % MOD * dp2[v] % MOD * dp2[v])) % MOD;
            }
        }
    }
    cout << (total - bad + MOD) % MOD  << endl;
}