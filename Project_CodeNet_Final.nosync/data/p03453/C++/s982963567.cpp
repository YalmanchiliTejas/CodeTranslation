#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define pb push_back
#define mp make_pair
#define taskname "A"

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 1e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;

vector<ii> adj[maxn];
int way[2][maxn] , n , m , s , t;
ll dis[2][maxn];
void DIJ(int way[maxn] , ll dis[maxn] , int st){
    fill_n(dis,maxn,1e18);
    dis[st] = 0;way[st] = 1;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push(mp(0,st));
    while(pq.size()){
        auto u = pq.top();pq.pop();
        if(dis[u.second] != u.first)continue;
        for(ii c : adj[u.second]){
            if(dis[c.first] > u.first + c.second){
                dis[c.first] = u.first + c.second;
                pq.push(mp(dis[c.first],c.first));
                way[c.first] = way[u.second];
            }else if(dis[c.first] == u.first + c.second){
                way[c.first] += way[u.second];
                if(way[c.first] >= mod)way[c.first] -= mod;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n >> m >> s >> t;
    for(int i = 1 ; i <= m ; ++i){
        int u , v , c;cin >> u >> v >> c;
        adj[u].pb(mp(v,c));
        adj[v].pb(mp(u,c));
    }
    DIJ(way[0],dis[0],s);
    DIJ(way[1],dis[1],t);
    int res = (ll)way[0][t] * way[0][t] % mod;
    for(int i = 1 ; i <= n ; ++i){
        if(dis[0][i] * 2 == dis[0][t]){
            res -= (ll)way[1][i] * way[1][i] % mod * way[0][i] % mod * way[0][i]  % mod;
            if(res < 0)res += mod;
        }
        for(ii c : adj[i]){
            if(dis[0][i] + c.second + dis[1][c.first] == dis[0][t] &&
                dis[0][i] * 2 < dis[0][t] && dis[1][c.first] * 2 < dis[0][t]){
                res -= (ll)way[0][i] * way[0][i] % mod * way[1][c.first] % mod * way[1][c.first] % mod;
                if(res < 0)res += mod;
            }
        }
    }
    cout << res;
}
