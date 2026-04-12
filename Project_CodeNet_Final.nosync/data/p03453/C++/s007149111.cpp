#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

constexpr int P = 1000000007;

struct Graph {
    struct Edge {
        bool operator<(const Edge& o) const {
            return c > o.c; // 逆
        }
        int i;
        int64_t c;
    };
    Graph(int n) : v(n), e(n) {}
    void add_edge(int i, int j, int c) {
        e[i].push_back({ j, c });
    }
    void dijkstra(int i, int j) {
        priority_queue<Edge> q;
        fill(v.begin(), v.end(), (int64_t)1 << 60);
        q.push({ i, v[i] = 0 });
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            a.push_back(p.i);
            if (p.i == j) break;
            if (p.c > v[p.i]) continue;
            for (const auto& o : e[p.i]) {
                int64_t c = p.c + o.c;
                if (c < v[o.i]) q.push({ o.i, v[o.i] = c });
            }
        }
    }
    int64_t solve() {
        int n = v.size();
        int k = a.size();
        vector<int> b0(n), b1(n);
        b0[a.front()] = 1;
        for (int j = 1; j < k; j++) {
            int i = a[j];
            int64_t t = 0;
            for (Edge& o : e[i]) {
                if (v[i] == v[o.i] + o.c) t += b0[o.i];
            }
            b0[i] = t % P;
        }
        b1[a.back()] = 1;
        for (int j = k - 1 - 1; j >= 0; j--) {
            int i = a[j];
            int64_t t = 0;
            for (Edge& o : e[i]) {
                if (v[i] + o.c == v[o.i]) t += b1[o.i];
            }
            b1[i] = t % P;
        }
        int64_t r = 0;
        int64_t d = v[a.back()];
        for (int i = 0; i < n; i++) {
            if (v[i] * 2 == d) {
                int64_t t = (int64_t)b0[i] * b1[i] % P;
                r += t * t;
                r %= P;
            }
            if (v[i] * 2 < d) {
                for (Edge& o : e[i]) {
                    if (v[i] + o.c == v[o.i] && v[o.i] * 2 > d) {
                        int64_t t = (int64_t)b0[i] * b1[o.i] % P;
                        r += t * t;
                        r %= P;
                    }
                }
            }
        }
        int64_t t = b0[a.back()];
        r = t * t - r;
        r %= P;
        if (r < 0) r += P;
        return r;
    }
    vector<int> a;
    vector<int64_t> v;
    vector<vector<Edge>> e;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;
    s--; t--;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        g.add_edge(a, b, c);
        g.add_edge(b, a, c);
    }

    g.dijkstra(s, t);

    cout << g.solve() << endl;

    return 0;
}