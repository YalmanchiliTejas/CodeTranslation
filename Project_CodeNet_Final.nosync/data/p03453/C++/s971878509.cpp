#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <cassert>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;

class Graph {
    int n;
    vector<vector<pair<int, double>>> adj;
    vector<double> d;
    vector<long> num;
    vector<double> de;
    bool negLoop = false;
    
public:
    Graph(int n) {
        this->n = n;
        adj = vector<vector<pair<int, double>>>(n, vector<pair<int, double>>());
    }
    void addArc(int a, int b, double w) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        adj[a].push_back(make_pair(b, w));
    }
    
    void addEdge(int a, int b, double w) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    
    void bf(int a) {
        d = vector<double>(n, INF);
        de = vector<double>(n);
        d[a] = 0;
        vector<pair<P, double>> edges;
        REP(i,n) {
            for (auto j: adj[i]) {
                edges.push_back(make_pair(P(i,j.first), j.second));
            }
        }
        int loopcnt = 0;
        while (1) {
            loopcnt++;
            bool update = false;
            for (auto e: edges) {
                if (d[e.first.first] != INF && d[e.first.second] > d[e.first.first] + e.second) {
                    if (loopcnt < n) de[e.first.second] = d[e.first.first] + e.second;
                    d[e.first.second] = d[e.first.first] + e.second;
                    update = true;
                }
            }
            if (!update) break;
            if (loopcnt == 2 * n) {
                negLoop = true;
                break;
            }
        }
    }
    
    bool hasNegLoop() {
        return negLoop;
    }
    
    bool hasNegLoop(int a) {
        return d[a] != de[a];
    }
    
    void dijkstra(int a) {
        d = vector<double>(n, INF);
        num = vector<long>(n);
        d[a] = 0;
        num[a] = 1;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
        q.push(make_pair(0, a));
        
        while (!q.empty()) {
            double cd = q.top().first;
            int u = q.top().second;
            q.pop();
            
            if (d[u] < cd) continue;
            for (auto i: adj[u]) {
                if (d[i.first] > d[u] + i.second) {
                    d[i.first] = d[u] + i.second;
                    num[i.first] = num[u];
                    q.push(make_pair(d[i.first], i.first));
                } else if (d[i.first] == d[u] + i.second) {
                    num[i.first] += num[u];
                    num[i.first] %= MOD;
                }
            }
        }
    }
    
    double dist(int a) {
        return d[a];
    }
    
    long get_num(int a) {
        return num[a];
    }
};

struct edge {
    int from, to, cost;
};

int main() {
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    vector<edge> edges;
    Graph st(n), ts(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        edges.push_back({u, v, d});
        edges.push_back({v, u, d});
        st.addEdge(u, v, d);
        ts.addEdge(u, v, d);
    }
    
    st.dijkstra(s);
    ts.dijkstra(t);
    
    long mindist = st.dist(t);
    assert(mindist == ts.dist(s));
    assert(st.get_num(t) == ts.get_num(s));
    long ans = st.get_num(t) * ts.get_num(s) % MOD;
    for (int i = 0; i < n; i++) {
        if (st.dist(i) * 2 == mindist) {
            ans -= st.get_num(i) * st.get_num(i) % MOD * ts.get_num(i) % MOD * ts.get_num(i) % MOD;
            ans %= MOD;
        }
    }
    for (auto e: edges) {
        if (2 * st.dist(e.from) < mindist && 2 * st.dist(e.to) > mindist && st.dist(e.from) + e.cost == st.dist(e.to) && st.dist(e.from) + e.cost + ts.dist(e.to) == mindist) {
            ans -= st.get_num(e.from) * st.get_num(e.from) % MOD * ts.get_num(e.to) % MOD * ts.get_num(e.to) % MOD;
            ans %= MOD;
        }
    }
    cout << (ans + MOD) % MOD << endl;
}
