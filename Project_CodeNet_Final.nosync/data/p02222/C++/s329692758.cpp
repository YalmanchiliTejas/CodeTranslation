#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
const int INF = 1e10;
const int MOD = 1e9 + 7;
#define dump(x)                             \
    if (dbg) {                              \
        cerr << #x << " = " << (x) << endl; \
    }
#define overload4(_1, _2, _3, _4, name, ...) name
#define FOR1(n) for (ll i = 0; i < (n); ++i)
#define FOR2(i, n) for (ll i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORR(i, a, b) for (int i = (a); i <= (b); ++i)
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return 1;
    } else
        return 0;
}
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    } else
        return 0;
}
void Yes(bool flag = true) {
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void No(bool flag = true) {
    Yes(!flag);
}
void YES(bool flag = true) {
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
void NO(bool flag = true) {
    YES(!flag);
}
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define P pair<int, int>
//#define V vector<int>
//#define S set<int>
#define itn int
bool dbg = false;
template <typename sum_t, typename key_t>
struct ReRooting {
    struct Edge {
        int to;
        key_t data;
        sum_t dp, ndp;
    };

    using F = function<sum_t(sum_t, sum_t)>;
    using G = function<sum_t(sum_t, key_t)>;

    vector<vector<Edge>> g;
    vector<sum_t> subdp, dp;
    const sum_t ident;
    const F f;
    const G gg;

    ReRooting(int V, const F f, const G g, const sum_t& ident)
        : g(V), f(f), gg(g), ident(ident), subdp(V, ident), dp(V, ident) {}

    void add_edge(int u, int v, const key_t& d) {
        g[u].emplace_back((Edge){v, d, ident, ident});
        g[v].emplace_back((Edge){u, d, ident, ident});
    }

    void add_edge_bi(int u, int v, const key_t& d, const key_t& e) {
        g[u].emplace_back((Edge){v, d, ident, ident});
        g[v].emplace_back((Edge){u, e, ident, ident});
    }

    void dfs_sub(int idx, int par) {
        for (auto& e : g[idx]) {
            if (e.to == par)
                continue;
            dfs_sub(e.to, idx);
            subdp[idx] = f(subdp[idx], gg(subdp[e.to], e.data));
        }
    }

    void dfs_all(int idx, int par, const sum_t& top) {
        sum_t buff{ident};
        for (int i = 0; i < (int)g[idx].size(); i++) {
            auto& e = g[idx][i];
            e.ndp = buff;
            e.dp = gg(par == e.to ? top : subdp[e.to], e.data);
            buff = f(buff, e.dp);
        }
        dp[idx] = buff;
        buff = ident;
        for (int i = (int)g[idx].size() - 1; i >= 0; i--) {
            auto& e = g[idx][i];
            if (e.to != par)
                dfs_all(e.to, idx, f(e.ndp, buff));
            e.ndp = f(e.ndp, buff);
            buff = f(buff, e.dp);
        }
    }

    vector<sum_t> build() {
        dfs_sub(0, -1);
        dfs_all(0, -1, ident);
        return dp;
    }
};
//https://ei1333.hateblo.jp/entry/2018/12/21/004022

itn N, a[101010], b[101010];

#define node vector<int>
/*
struct node {
    vector<int> l;
};
*/

void solve() {
    auto f = [](node a, node b) {
        a.insert(a.end(), all(b));
        sort(all(a), greater<int>());
        if (a.size() > 3) {
            a.erase(a.begin() + 3, a.end());
        }
        return a;
    };
    auto g = [](node a, int x) {
        if (a.size() > 1) {
            a.erase(a.begin() + 1, a.end());
        }
        if (a.size() == 1) {
            a[0]++;
        }
        //cout << a[0] << endl;
        return a;
    };

    node ident = {0};
    ReRooting<node, int> tree(N, f, g, ident);

    FOR(N - 1) {
        tree.add_edge(a[i], b[i], 0);
    }

    int MAX = 0;
    for (auto& x : tree.build()) {
        if (x.size() == 3 && x[2] != 0) {
            if (x[0] == x[2])
                chmax(MAX, x[0] * 2);
            else
                chmax(MAX, x[0] + x[2] + 1);
        }
    }
    //cout << MAX << endl;

    FOR(i, 1, N + 1) {
        if (i == 1 || i == 2) {
            cout << 1;
        } else {
            if (i >= MAX)
                cout << 1;
            else
                cout << 0;
        }
    }
    cout << endl;
}


signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    FOR(N - 1) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    solve();
    return 0;
}

