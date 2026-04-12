#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i,a,b) for(ll i=(a);i<(b);i++)
#define all(a)  (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)
//#define INF (1LL<<59)

#define MAX_V 10000

struct edge{int to, cost;};
vector<edge> G[MAX_V];

int dfs(vector<int> &depth, int cur, int prev){
    depth[cur] = 0;
    
    for(auto e:G[cur]){
        if(e.to==prev)continue;
        depth[cur] = max(depth[cur], e.cost + dfs(depth, e.to, cur));
    }
    return depth[cur];
}


void dfs2(const vector<int> &depth, vector<int> &ans, int cur, int prev, int d_par){
    vector<pii> cand;
    cand.pb(0,-1);
    
    for(auto e:G[cur]){
        if(e.to==prev){
            ans[cur] = max(ans[cur], d_par+e.cost);
            cand.pb(d_par+e.cost, e.to);
            continue;
        }
        else{
            ans[cur] = max(ans[cur], e.cost+depth[e.to]);
//            cout<<cur<<" -> "<<e.to<<endl;
//            cout<<e.cost<<" "<<depth[e.to]<<endl;
            cand.pb(e.cost+depth[e.to], e.to);
        }
    }
    sort(all(cand),greater<pii>());
    
    for(auto e:G[cur]){
        if(e.to==prev)continue;
        if(e.to==cand[0].second)dfs2(depth, ans, e.to, cur, cand[1].first);
        else                    dfs2(depth, ans, e.to, cur, cand[0].first);
    }
}


int main(){
    int v;
    cin>>v;
    
    rep(i,v-1){
        int s,t,c;
        cin>>s>>t>>c;
        G[s].pb(edge{t,c});
        G[t].pb(edge{s,c});
    }
    
    vector<int> depth(v,0);
    depth[0] = dfs(depth,0,-1);
    
    vector<int> ans(v,0);
    dfs2(depth, ans, 0, -1, INF);
    
    
    for(auto e:ans)cout<<e<<endl;
}