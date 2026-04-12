#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
#define rep(i,n) for(ll i=0;i<(n);i++)

using namespace std;

struct Edge{
    ll to;
    ll cost;
};
 
struct Node{
    ll pos;
    ll cost;
    bool operator< (const Node &r) const{
        return cost > r.cost;
    }
};
 

vector<ll> x(1e5+5);
vector<ll> y(1e5+5);
 
ll dijkstra(vector<Edge>* g, ll n){ 
    ll sum = 0;

    priority_queue<Node> que;
    que.push({0, 0});
    vector<ll> res(n, 1e10);
    ll cnt = 0;
    while(!que.empty() && cnt < n){
        Node n = que.top(); que.pop();
        if(res[n.pos] == 1e10){
            res[n.pos] = n.cost;
            cnt++;
        }
        else    continue;
        
        for(auto e : g[n.pos]){
            que.push({e.to, e.cost});
        }
    }

    for(auto e : res)   sum += e;
    
    return sum;
}
 
int main(){
    ll n;
    cin >> n;
    rep(i, n)   cin >> x[i] >> y[i];
 
 
    vector<Edge> g[n];

    vector<Node> xs;
    rep(i, n)   xs.push_back({i, x[i]});

    sort(xs.begin(), xs.end());
    rep(i, n-1){
        ll cost = abs(xs[i].cost - xs[i+1].cost);
        g[xs[i].pos].push_back({xs[i+1].pos, cost});
        g[xs[i+1].pos].push_back({xs[i].pos, cost});
    }

    vector<Node> ys;
    rep(i, n)   ys.push_back({i, y[i]});

    sort(ys.begin(), ys.end());
    rep(i, n-1){
        ll cost = abs(ys[i].cost - ys[i+1].cost);
        g[ys[i].pos].push_back({ys[i+1].pos, cost});
        g[ys[i+1].pos].push_back({ys[i].pos, cost});
    }
  
 
    cout << dijkstra(g, n) << endl;
 
 
    return 0;
}