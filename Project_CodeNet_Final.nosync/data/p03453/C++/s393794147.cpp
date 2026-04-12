#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
        int s, e;
        long long v;
        Edge(int a, int b, long long c){
            s = a;
            e = b;
            v = c;
        }
        bool operator<(const Edge &o) const{
            return v>o.v;
        }
};
vector<Edge> adj[100001];
int n;
long long mod = 1000000007LL;
vector<long long> bfs(int s){
    vector<long long> ret;
    ret.resize(n);
    for(int i = 0; i<n; i++){
        ret[i] = -1LL;
    }
    priority_queue<Edge> pq;
    pq.push(Edge(s,s,0LL));
    while(pq.size()>0){
        Edge now = pq.top();
        pq.pop();
        if(ret[now.e]>=0LL){
            continue;
        }
        ret[now.e] = now.v;
        for(int i = 0; i<adj[now.e].size(); i++){
            pq.push(Edge(-1,adj[now.e][i].e,adj[now.e][i].v+now.v));
        }
    }
    return ret;
}
vector<long long> bfs2(int s){
    vector<long long> ret;
    ret.resize(n);
    for(int i = 0; i<n; i++){
        ret[i] = -1LL;
    }
    priority_queue<Edge> pq;
    pq.push(Edge(s,s,0LL));
    while(pq.size()>0){
        Edge now = pq.top();
        pq.pop();
        if(ret[now.e]>=0LL){
            continue;
        }
        ret[now.e] = now.v;
        for(int i = 0; i<adj[now.e].size(); i++){
            pq.push(Edge(-1,adj[now.e][i].e,adj[now.e][i].v+now.v));
        }
    }
    vector<long long> ret2;
    ret2.resize(n);
    for(int i = 0; i<n; i++){
        ret2[i] = 0LL;
    }
    ret2[s] = 1LL;
    for(int i = 0; i<n; i++){
        pq.push(Edge(i,i,ret[i]));
    }
    while(pq.size()>0){
        Edge now = pq.top();
        pq.pop();
        for(int i = 0; i<adj[now.e].size(); i++){
            if(now.v+adj[now.e][i].v == ret[adj[now.e][i].e]){
                ret2[adj[now.e][i].e] = (ret2[adj[now.e][i].e]+ret2[now.e])%mod;
            }
        }
    }
    return ret2;
}
int main(){
    int m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    for(int i = 0; i<m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back(Edge(a,b,c));
        adj[b].push_back(Edge(b,a,c));
    }
    vector<long long> a = bfs(s);
    vector<long long> b = bfs(t);
    vector<long long> wa = bfs2(s);
    vector<long long> wb = bfs2(t);
    long long ans = (wa[t]*wb[s])%mod;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<adj[i].size(); j++){
            Edge e = adj[i][j];
            if(a[e.s]+b[e.e]+e.v != a[t]){
                continue;
            }
            if(a[e.s]+e.v<=b[e.e] || b[e.e]+e.v<=a[e.s]){
                continue;
            }
            ans -= ((wa[e.s]*wb[e.e])%mod)*((wa[e.s]*wb[e.e])%mod);
            ans %= mod;
            ans = (ans+mod)%mod;
        }
    }
    for(int i = 0; i<n; i++){
        if(a[i]==b[i] && a[i]+b[i]==a[t]){
            ans -= ((wa[i]*wb[i])%mod)*((wa[i]*wb[i])%mod);
            ans %= mod;
            ans = (ans+mod)%mod;
        }
    }
    cout << ans << endl;
}