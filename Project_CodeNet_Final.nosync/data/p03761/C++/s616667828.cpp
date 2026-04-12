#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
struct LowestCommonAncestor {
    int n, sn;
    vector<int> id, vs, dep;
    vector<pair<int, int>> node;
    LowestCommonAncestor(vector<vector<int>> g, int root = 0)
        : n(sz(g)), id(n), vs(n * 2 - 1), dep(n * 2 - 1) {
        int k = 0;
        dfs(root, -1, 0, k, g);
        sn = 1;
        while (sn < sz(dep)) {
            sn *= 2;
        }
        node.assign(2 * sn - 1, make_pair(INF, INF));
        for (int i = 0; i < sz(dep); i++) {
            node[sn + i - 1] = make_pair(dep[i], i);
        }
        for (int i = sn - 1; i >= 1; i--) {
            node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }
    void dfs(int now, int pre, int d, int &k, const vector<vector<int>> &g) {
        id[now] = k;
        vs[k] = now;
        dep[k++] = d;
        for (int nxt : g[now]) {
            if (nxt == pre) continue;
            dfs(nxt, now, d + 1, k, g);
            vs[k] = now;
            dep[k++] = d;
        }
    }
    pair<int, int> query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = sn;
        if (r <= a || b <= l) return make_pair(INF, INF);
        if (a <= l && r <= b) return node[k];
        auto vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        auto vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
    int get(int u, int v) {
        int l = min(id[u], id[v]);
        int r = max(id[u], id[v]) + 1;
        return vs[query(l, r).second];
    }
    int depth(int u) {
        return dep[id[u]];
    }
    int dist(int u, int v) {
        return depth(u) + depth(v) - 2 * depth(get(u, v));
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> cnt(26, INF);
    rep(i, n) {
        string s;
        cin >> s;
        vector<int> now(26, 0);
        for (char c : s) {
            now[c - 'a']++;
        }
        rep(i, 26) {
            chmin(cnt[i], now[i]);
        }
    }
    rep(i, 26) {
        if (cnt[i] == INF) continue;
        while (cnt[i]--) cout << (char)(i + 'a');
    }
    cout << endl;
}