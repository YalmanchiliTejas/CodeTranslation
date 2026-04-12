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

int inv(int n) {
    int m = P, y = 0, v = 1;
    while (1) {
        int q = m / n;
        int r = m % n;
        if (r == 0) return v < 0 ? v + P : v;
        y -= v * q;
        swap(y, v);
        m = n;
        n = r;
    }
}

int64_t dd, ans;

struct Graph {
    struct Edge {
        bool operator<(const Edge& o) const {
            return c > o.c; // 逆
        }
        int i;
        int64_t c;
    };
    Graph(int n) : a(n), e(n) {
        for (int i = 0; i < 4; i++) {
            vv[i] = vector<int64_t>(n);
        }
    }
    void add_edge(int i, int j, int c) {
        e[i].push_back({ j, c });
    }
    void dijkstra(int i, int idx) {
        priority_queue<Edge> q;
        auto& v = vv[idx];
        auto& u = vv[idx + 2];
        fill(v.begin(), v.end(), (int64_t)1 << 60);
        q.push({ i, v[i] = 0 });
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            if (p.c > v[p.i]) continue;
            for (const auto& o : e[p.i]) {
                int64_t c = p.c + o.c;
                if (c < v[o.i]) q.push({ o.i, v[o.i] = c });

                if (v[o.i] == p.c - o.c) u[p.i] += u[o.i];
            }
            u[p.i] %= P;
        }
    }
    void dfs(int i, int idx) {
        auto& v = vv[idx];
        int64_t c = v[i];
        //cout << c << ' ' << vv[2][i] << ' ' << vv[3][i] << endl;
        if (a[i]) return; else a[i] = 1;

        if (c * 2 == dd) {
            int64_t t = vv[2][i] * vv[3][i] % P;
            ans += t * t;
            ans %= P;
        }

        for (Edge& o : e[i]) {
            if (v[o.i] != c + o.c || vv[idx ^ 1][o.i] != dd - (c + o.c)) continue;

            if (c * 2 < dd && v[o.i] * 2 > dd) {
                int64_t t = vv[2][i] * vv[3][o.i] % P;
                ans += t * t;
                ans %= P;
            }

            dfs(o.i, idx);
        }
    }
    vector<int64_t> vv[4];
    vector<int> a;
    vector<vector<Edge>> e;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int s[2];
    cin >> s[0] >> s[1];
    s[0]--; s[1]--;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        g.add_edge(a, b, c);
        g.add_edge(b, a, c);
    }

    for (int i = 0; i < 2; i++) {
        g.vv[i + 2][s[i]] = 1;
        g.dijkstra(s[i], i);
    }
    dd = g.vv[0][s[1]];
    g.dfs(s[0], 0);

    int64_t t = g.vv[2][s[1]];
    ans = t * t - ans;
    ans %= P;
    if (ans < 0) ans += P;

    cout << ans << endl;

    return 0;
}