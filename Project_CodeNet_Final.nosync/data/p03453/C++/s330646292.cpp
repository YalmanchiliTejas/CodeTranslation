#include <bits/stdc++.h>

//#define DEBUG 1

#define int long long
#define for0(i,n) for (int i=0; i<n; i++)
#define iter(c) for(auto it=c.begin(); it!=c.end(); it++)
#define iter2(c) for(auto it2=c.begin(); it2!=c.end(); it2++)
#define pb push_back
#define ms(a,z) memset(a,z,sizeof(a));
#define mp make_pair
#define X first
#define Y second
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define all(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define pmod(x,m) (((x)%(m)+m)%m)
#ifdef int
#define read(x) scanf("%lld",&x);
#else
#define read(x) scanf("%d",&x);
#endif

#ifdef DEBUG
#define nl cout<<"\n";
#define pr(x) cout<<(x)<<" ";
#define prl(x) cout<<#x " = "<<x<<endl;
#define prp(x) cout<<"("<<(x).first<<" "<<(x).second<<") ";
#define printv(v) {for(int _=0; _<sz(v); _++) cout<<v[_]<<" "; cout<<"\n";}
#define printa(a,s) {for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";}
#define print2D(a,m,n) {for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";} cout<<"\n";}
#define priter(v) iter(v) {pr(*it)} nl
#define debug cout<<"ok at line "<<__LINE__<<endl;
#else
#define nl
#define pr(x)
#define prl(x)
#define prp(x)
#define printv(v)
#define printa(a,s)
#define print2D(a,m,n)
#define priter(v)
#define debug
#endif
#define MAXN 100000

using namespace std;

typedef long long ll;

const int INF = 2147483647;
const long long INFL = 9223372036854775807LL;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;

struct edge
{
    int u,v,d;
};

vector<edge> adj[MAXN+5];
ll dist[2][MAXN+5];
ll ways[2][MAXN+5];
bool node_on_path[MAXN+5];
set<pair<int,int>> edges_on_path;
vector<int> from[MAXN+5];
bool visited[MAXN+5];

ll search(int source, int sink, int n, ll dist[MAXN+5], ll ways[MAXN+5])
{
    for0(i,n) {
        dist[i] = INFL;
        ways[i] = 0;
        from[i].clear();
    }
    dist[source] = 0;
    ways[source] = 1;
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,source});
    
    while (!pq.empty()) {
        ll d,top;
        tie(d,top) = pq.top();
        pq.pop();
        d *= -1;
        if (d > dist[top])
            continue;
        
        if (top == sink)
            return d;
        
        iter(adj[top]) {
            int nxt = it->v;
            ll nxt_dist = d + it->d;
            if (nxt_dist == dist[nxt]) {
                ways[nxt] = (ways[nxt] + ways[top]) % MOD;
                from[nxt].pb(top);
            }
            else if (nxt_dist < dist[nxt]) {
                ways[nxt] = ways[top];
                dist[nxt] = nxt_dist;
                from[nxt].clear();
                from[nxt].pb(top);
                pq.push({-nxt_dist,nxt});
            }
        }
    }
}

void find_good_nodes(int source, int sink)
{
    ms(node_on_path,false);
    queue<int> q;
    q.push(sink);
    ms(visited,false);
    visited[sink] = true;
    edges_on_path.clear();
    
    while (!q.empty()) {
        int top = q.front(); q.pop();
        node_on_path[top] = true;
        
        iter(from[top]) {
            if (not visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
            edges_on_path.insert({*it,top});
        }
    }
}

int32_t main()
{
    #ifdef DEBUG
    //freopen("C.txt","r",stdin);
    //freopen("","w",stdout);
    #endif

    int n,m;
    cin >> n >> m;
    int s,t;
    cin >> s >> t;
    s--; t--;
    
    vector<edge> all_edges;
    for0(i,m) {
        int u,v,d;
        read(u); read(v); read(d);
        u--; v--;
        all_edges.pb((edge){u,v,d});
        adj[u].pb((edge){u,v,d});
        adj[v].pb((edge){v,u,d});
    }
    
    search(s,t,n,dist[0],ways[0]);
    search(t,s,n,dist[1],ways[1]);
    /*for0(i,n) {
        pr(i) printv(from[i])
    }*/
    find_good_nodes(t,s);
    
    print2D(dist,2,n)
    print2D(ways,2,n)
    printa(node_on_path,n)
    
    ll tot = ways[0][t] * ways[0][t] % MOD;
    prl(tot)
    ll bad = 0;
    for (int i=0; i<n; i++) {
        if (node_on_path[i] and dist[0][i] == dist[1][i]) {
            ll w = ways[0][i] * ways[1][i] % MOD;
            pr("meet at node") pr(i) pr(w) nl
            bad = (bad+w*w) % MOD;
        }
    }
    
    /*iter(edges_on_path) {
        prp(*it)
    } nl*/
    
    iter(all_edges) {
        //if (dist[0][it->u] == INFL or dist[0][it->v] == INFL)
        //    continue;
        if (edges_on_path.find({it->u,it->v}) == edges_on_path.end() and edges_on_path.find({it->v,it->u}) == edges_on_path.end())
            continue;
        //edge is on shortest path
        
        int u,v;
        if (dist[0][it->u] < dist[0][it->v]) 
            u = it->u, v = it->v;
        else 
            u = it->v, v = it->u;
        
        ll t_a_u = dist[0][u];
        ll t_a_v = dist[0][v];
        ll t_b_u = dist[1][u];
        ll t_b_v = dist[1][v];
        assert(t_a_u+it->d == t_a_v and t_b_v+it->d == t_b_u);
        if ((t_a_u <= t_b_v and t_b_v < t_a_v) or (t_a_u < t_b_u and t_b_u <= t_a_v)) {
            pr("meet on edge") pr(u) pr(v) nl 
            ll w = ways[0][u] * ways[1][v] % MOD;
            bad = (bad+w*w) % MOD;
        }
    }
    
    tot = pmod(tot-bad,MOD);
    cout<<tot<<endl;
    return 0;
}
