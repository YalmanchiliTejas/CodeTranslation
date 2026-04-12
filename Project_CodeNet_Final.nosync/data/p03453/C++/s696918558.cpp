#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

/*
#define cin ifs
#define cout ofs
ifstream ifs("in.txt");
ofstream ofs("out.txt");
//*/

int M, S, T;
vector<int> ns;
int mod = 1e9 + 7;
//ダイクストラ法を用いて単一始点最短路問題を解く
const int MAX_V = 100000;
const int INF = 1e12;

struct edge {
    int to, cost;
};
typedef pair<int, int> P;

int V;
vector<edge> G[MAX_V];
int d1[MAX_V], n1[MAX_V];
int d2[MAX_V], n2[MAX_V];

void dijkstra(int s, int d[MAX_V], int n[MAX_V]) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, INF);
    d[s] = 0;
    n[s] = 1;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                n[e.to] = n[v];
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            } else if (d[e.to] == d[v] + e.cost) {
                n[e.to] += n[v];
                n[e.to] %= mod;
            }
        }
    }
}

signed main() {
    cin >> V >> M >> S >> T;
    S--;
    T--;
    for (int i = 0; i < M; i++) {
        int U, V, D;
        cin >> U >> V >> D;
        G[U - 1].push_back({V - 1, D});
        G[V - 1].push_back({U - 1, D});
    }
    dijkstra(S, d1, n1);
    dijkstra(T, d2, n2);
    for (int i = 0; i < V; i++) {
        if (d1[i] * 2 == d1[T]) {
            ns.push_back(n1[i] * n2[i] % mod);
        } else if (d1[i] * 2 < d1[T]) {
            for (int j = 0; j < G[i].size(); j++) {
                edge e = G[i][j];
                if (d1[i] + d2[e.to] + e.cost == d1[T] &&
                    d1[e.to] * 2 > d1[T]) {
                    ns.push_back(n1[i] * n2[e.to] % mod);
                }
            }
        }
    }
    int ans = 0, sum = 0;
    for (int i = 0; i < ns.size(); i++) {
        sum += ns[i];
        sum %= mod;
    }
    for (int i = 0; i < ns.size(); i++) {
        ans += ((ns[i] % mod) * ((sum + mod - ns[i]) % mod)) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}