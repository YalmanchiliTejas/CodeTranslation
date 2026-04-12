// http://drken1215.hatenablog.com/entry/2018/02/09/003200
// 確認用
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long MOD = 1000000007;
inline long long mod(long long a, long long m) { return (a % m + m) % m; }

typedef pair<long long, int> Edge;

const int MAX = 110000;
const long long INF = 1LL<<59;
int N, M, S, T;
vector<Edge> G[MAX];

long long ds[MAX], ns[MAX], dt[MAX], nt[MAX];

int main() {
    while (cin >> N >> M >> S >> T) {
        --S, --T;
        for (int i = 0; i < MAX; ++i) G[i].clear();
        for (int i = 0; i < M; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            --u, --v;
            G[u].push_back(Edge(d, v));
            G[v].push_back(Edge(d, u));
        }
        for (int i = 0; i < MAX; ++i) {
            ds[i] = dt[i] = INF;
            ns[i] = nt[i] = 0;
        }
        ds[S] = 0;
        ns[S] = 1;
        priority_queue<Edge, vector<Edge>, greater<Edge> > que;
        que.push(Edge(0, S));
        while (!que.empty()) {
            long long curd = que.top().first;
            int cur = que.top().second;
            que.pop();
            if (ds[cur] < curd) continue;
            for (auto e : G[cur]) {
                if (ds[e.second] > ds[cur] + e.first) {
                    ds[e.second] = ds[cur] + e.first;
                    ns[e.second] = ns[cur];
                    que.push(Edge(ds[e.second], e.second));
                }
                else if (ds[e.second] == ds[cur] + e.first) {
                    ns[e.second] += ns[cur];
                    ns[e.second] %= MOD;
                }
            }
        }
        dt[T] = 0;
        nt[T] = 1;
        que.push(Edge(0, T));
        while (!que.empty()) {
            long long curd = que.top().first;
            int cur = que.top().second;
            que.pop();
            if (dt[cur] < curd) continue;
            for (auto e : G[cur]) {
                if (dt[e.second] > dt[cur] + e.first) {
                    dt[e.second] = dt[cur] + e.first;
                    nt[e.second] = nt[cur];
                    que.push(Edge(dt[e.second], e.second));
                }
                else if (dt[e.second] == dt[cur] + e.first) {
                    nt[e.second] += nt[cur];
                    nt[e.second] %= MOD;
                }
            }
        }

        long long D = ds[T];
        long long res = (ns[T] * nt[S]) % MOD;
        for (int v = 0; v < N; ++v) {
            // v 上を引く
            if (ds[v] == dt[v] && ds[v] + dt[v] == D) {
                long long sub = (ns[v] * nt[v]) % MOD;
                sub = (sub * sub) % MOD;
                res = mod(res - sub, MOD);
            }
            // e = (from -> to) 上を引く
            for (auto e : G[v]) {
                int from = v;
                int to = e.second;
                long long dis = e.first;
                if (ds[from] + dis + dt[to] != D) continue;
                if (ds[from] == dt[from] || ds[to] == dt[to]) continue;
                if (ds[from] < dt[from] && ds[to] > dt[to]) {
                    long long sub = (ns[from] * nt[to]) % MOD;
                    sub = (sub * sub) % MOD;
                    res = mod(res - sub, MOD);
                }
            }
        }
        
        cout << res << endl;
    }
}