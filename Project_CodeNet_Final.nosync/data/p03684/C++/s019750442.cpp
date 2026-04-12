#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using P  = pair<ll,ll>;

struct Edge{
    using Cost = ll;
    ll to;
    Cost cost;
    Edge(ll t, Cost c) : to(t), cost(c){} 
};
using Edges = vector<Edge>;
using Graph = vector<vector<Edge>>;

bool operator < (const Edge &e,const Edge &f){
    return e.cost != f.cost ? e.cost > f.cost:
        e.to > f.to;
}

ll MST(const Graph &g, int r=0){
    ll n=g.size();
    ll total=0;

    vector<bool> visited(n);
    priority_queue<Edge> q;
    q.push(Edge(r,0));
    while(!q.empty()){
        Edge e=q.top();q.pop();
        if(visited[e.to]) continue;
        //cout<<e.to<<" "<<e.cost<<endl;
        total += e.cost;
        visited[e.to] = true;
        for(int i=0;i<(int)g[e.to].size();i++){
            if(!visited[g[e.to][i].to]) q.push(g[e.to][i]);
        }
    }
    return total;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n;cin>>n;
    Graph g(n);
    vector<P> x,y;
    for(int i=0;i<n;i++){
        ll xtmp,ytmp;cin>>xtmp>>ytmp;
        x.push_back(P(xtmp,i));
        y.push_back(P(ytmp,i));
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(int i=1;i<n;i++){
        ll s=x[i-1].second,t=x[i].second;
        ll c=x[i].first-x[i-1].first;
        g[s].push_back(Edge(t,c));
        g[t].push_back(Edge(s,c));
        //cout<<s<<" "<<t<<" "<<c<<endl;
        
        s=y[i-1].second;t=y[i].second;
        c=y[i].first-y[i-1].first;
        g[s].push_back(Edge(t,c));
        g[t].push_back(Edge(s,c));
        //cout<<s<<" "<<t<<" "<<c<<endl;
    }
    //cout<<endl;
    cout<<MST(g)<<endl;
}
