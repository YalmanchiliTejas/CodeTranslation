// Header {{{
#include <bits/stdc++.h>

using namespace std;
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;
typedef unsigned long long int ull;
typedef long long int ll;
#define rep(i,a,b) for (ll i=(a); i<(b); i++)
typedef pair<ll,ll> PLL;
// }}}
// {{{ MaxFlow
class MaxFlow{
    private:
        // destination, capacity, reverse edge index
        const ll inf=1e18;
        struct edge { ll to, cap, rev; };
        ll _n;
        vector<vector<edge>> G;
        vector<bool> used;

        ll dfs (ll src, ll dst, ll flow){
            if (src==dst)
                return flow;
            used[src]=true;
            rep(i,0,G[src].size()){
                edge &e = G[src][i];
                if (!used[e.to] && e.cap > 0) {
                    ll d = dfs(e.to, dst, min(flow, e.cap));
                    if (d>0){
                        e.cap -= d;
                        G[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

    public:
        MaxFlow (ll numOfVertex){
            _n = numOfVertex;
            G = vector<vector<edge>>(_n);
        }

        // 0<=src,dst<numOfVertex
        void addEdge(ll src, ll dst, ll cap) {
            G[src].push_back(edge{dst, cap, (ll)G[dst].size()});
            G[dst].push_back(edge{src, 0, (ll)G[src].size()-1});
        }

        ll maxFlow(ll src, ll dst){
            ll flow = 0;
            while(true){
                used = vector<bool>(_n, false);
                ll f = dfs(src, dst, inf);
                if (f==0){
                    return flow;
                }
                flow += f;
            }
        }
};
// }}}

ll n,m;
vector<vector<ll>> edge; // vertex id -> next vertex id's
vector<bool> used;

ll f(ll cur){
    ll res = 0;
    used[cur] = true;
    for (auto nex: edge[cur]){
        if (used[nex]){
            continue;
        }
        res += f(nex); 
    }


    if (res > 0){
        used[cur] = false;
        return res;
    }

    bool last = true;
    for(auto u: used) last &= u;
    used[cur] = false;
    return last ? 1 : 0;
}

signed main() {
    cin>>n>>m;
    edge.resize(n, vector<ll>());
    used.resize(n, false);
    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    cout<<f(0)<<endl;
    return 0;
}
