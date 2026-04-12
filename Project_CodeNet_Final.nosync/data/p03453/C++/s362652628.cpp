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
    struct VertexQ {
        bool operator<(const VertexQ& o) const {
            return c > o.c; // 逆
        }
        int i;
        int64_t c;
    };
    struct Vertex { int n; int64_t c; };
    struct Edge { int i, n, c; };
    Graph(int n, int m) : v(n, { -1 }), e(m), n(n), m(0) {}
    void add_edge(int i, int j, int c) {
        e[m] = { j, v[i].n, c };
        v[i].n = m;
        m++;
    }
    void dijkstra(int i, int j) {
        for (int i = 0; i < n; i++) v[i].c = (int64_t)1 << 60;
        priority_queue<VertexQ> q;
        q.push({ i, v[i].c = 0 });
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            a.push_back(p.i);
            if (p.i == j) break;
            if (p.c > v[p.i].c) continue;
            for (int j = v[p.i].n; j >= 0; j = e[j].n) {
                Edge& o = e[j];
                int64_t c = p.c + o.c;
                if (c < v[o.i].c) q.push({ o.i, v[o.i].c = c });
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
            for (int j = v[i].n; j >= 0; j = e[j].n) {
                Edge& o = e[j];
                if (v[i].c == v[o.i].c + o.c) t += b0[o.i];
            }
            b0[i] = t % P;
        }
        b1[a.back()] = 1;
        for (int j = k - 1 - 1; j >= 0; j--) {
            int i = a[j];
            int64_t t = 0;
            for (int j = v[i].n; j >= 0; j = e[j].n) {
                Edge& o = e[j];
                if (v[i].c + o.c == v[o.i].c) t += b1[o.i];
            }
            b1[i] = t % P;
        }
        int64_t r = 0;
        int64_t d = v[a.back()].c;
        for (int i = 0; i < n; i++) {
            if (v[i].c * 2 == d) {
                int64_t t = (int64_t)b0[i] * b1[i] % P;
                r += t * t;
                r %= P;
            }
            if (v[i].c * 2 < d) {
                for (int j = v[i].n; j >= 0; j = e[j].n) {
                    Edge& o = e[j];
                    if (v[i].c + o.c == v[o.i].c && v[o.i].c * 2 > d) {
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
    vector<Vertex> v;
    vector<Edge> e;
    int n, m;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;
    s--; t--;

    Graph g(n, m * 2);
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