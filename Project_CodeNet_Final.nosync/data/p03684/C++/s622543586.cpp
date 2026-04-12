#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define pye cout << "yes" << endl;
#define pno cout << "no" << endl;
#define pYe cout << "Yes" << endl;
#define pNo cout << "No" << endl;
#define pYE cout << "YES" << endl;
#define pNO cout << "NO" << endl;
#define prin(num) cout << num << endl;
#define REP(i, n) for(i=0; i<n; i++)
#define REPR(i, n) for(i=n; i>=0; i--)
#define FOR(i, m, n) for(i=m; i<n; i++)
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 10000000000
#define MOD 1000000007LL
#define MAX_V 100005
#define MAX_E 100005
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef priority_queue<P> PQ;

class Edge {
public:
    ll t, w;
    Edge (ll t, ll w): t(t), w(w) {}
};

ll N;
P x[100000], y[100000];
vector<Edge> G[200000];
ll d[100000], color[100000];

void prim() {
    ll i, u;
    for(i=0; i<N; i++) {
        d[i]=INF;
        color[i]=WHITE;
    }
    priority_queue<P> PQ;
    PQ.push(P(0, 0));
    d[0]=0;
    
    while(PQ.size()) {
        P f=PQ.top(); PQ.pop();
        u=f.second;
        
        color[u]=BLACK;
        if(d[u]<f.first*(-1)) continue;
        
        for(i=0; i<G[u].size(); i++) {
            Edge e=G[u][i];
            if(color[e.t]!=BLACK && d[e.t]>e.w) {
                d[e.t]=e.w;
                PQ.push(P(-d[e.t], e.t));
            }
            
        }
        
    }
    ll ans=0;
    for(i=0; i<N; i++) {
        ans+=d[i];
    }
    
    prin(ans);
}


void add_edge(ll s, ll t, ll w) {
    G[s].push_back(Edge(t, w));
    G[t].push_back(Edge(s, w));
}

int main(void) {
    ll i;
    cin >> N;
    for(i=0; i<N; i++) {
        cin >> x[i].first >> y[i].first;
        x[i].second=i;
        y[i].second=i;
    }
    sort(x, x+N);
    sort(y, y+N);
    
    for(i=0; i<N-1; i++) {
        add_edge(x[i].second, x[i+1].second, x[i+1].first-x[i].first);
        add_edge(y[i].second, y[i+1].second, y[i+1].first-y[i].first);
    }
    
    prim();
}