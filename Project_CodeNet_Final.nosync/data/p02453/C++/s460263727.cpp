#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 1000000007;

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return (t * t) % mod;
    } else {
        return (modpow(m, n - 1) * m) % mod;
    }
}

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)
template <typename A, size_t N, typename T> void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
struct LCA {
    vector<vector<int>> par;
    vector<int> d;
    int n;
    LCA(vector<vector<int>> graph, int root) {
        n = graph.size();
        par.resize(n, vector<int>(30));
        d.resize(n, 0);
        function<void(int, int, int)> dfs = [&](int c, int p, int depth) {
            d[c] = depth;
            par[c][0] = p;
            for (auto ch : graph[c]) {
                if (ch != p) dfs(ch, c, depth + 1);
            }
        };
        dfs(0, 0, 0);
        for (int j = 1; j < 30; j++) {
            REP(i, n) { par[i][j] = par[par[i][j - 1]][j - 1]; }
        }
    }
    int getdistance(int u, int v) { return (d[u] + d[v]) - 2 * (d[query(u, v)]); }
    int query(int u, int v) {
        if (d[u] > d[v]) {
            swap(u, v);
        }
        for (int i = 29; 0 <= i; i--) {
            if (d[u] <= d[par[v][i]]) {
                v = par[v][i];
            }
        }
        /* LCA */
        for (int i = 29; 0 <= i; i--) {
            if (par[v][i] != par[u][i]) {
                v = par[v][i];
                u = par[u][i];
            }
        }
        if (u == v) {
            return u;
        } else {
            return par[v][0];
        }
    }
};

struct UnionFind {
    vector<int> parent, size;
    UnionFind(int n) {
        parent.resize(n, -1);
        size.resize(n, 1);
    }
    void unite(int x, int y) {
        if (same(x, y)) {
            return;
        }
        x = root(x);
        y = root(y);
        if (size[x] <= size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
    bool same(int x, int y) { return (root(x) == root(y)); }
    int root(int x) {
        while (parent[x] != -1) {
            x = parent[x];
        }
        return x;
    }
    int getsize(int x) { return size[root(x)]; }
};
void aoj(vector<int> bs) {
    REP(i, bs.size() - 1) { cout << bs[i] << " "; }
    cout << bs[bs.size() - 1] << endl;
}

signed main() {
    int n;
    cin >> n;
    vector<int> as(n);
    REP(i, n) { cin >> as[i]; }
    int q;
    cin >> q;
    vector<int> k(q);
    REP(i, q) { cin >> k[i]; }
    // find an index of minimum value >= 5;
    // set limits
    REP(i, q) { cout << lower_bound(as.begin(), as.end(), k[i]) - as.begin() << endl; }
}
