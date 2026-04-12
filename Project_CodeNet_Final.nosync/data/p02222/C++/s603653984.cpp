#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const int inf  = 1LL << 30;
const lint mod = 1000000007;

// https://ei1333.hateblo.jp/entry/2018/12/21/004022
template <typename Data, typename T>
struct ReRooting {

    struct Node {
        int to, rev;
        Data data;
    };

    using F1 = function<T(T, T)>;
    using F2 = function<T(T, Data)>;

    vector<vector<Node>> g;
    vector<vector<T>> ldp, rdp;
    vector<int> lptr, rptr;
    const F1 f1;
    const F2 f2;
    const T ident;

    ReRooting(int n, const F1 &f1, const F2 &f2, const T &ident)
        : g(n), ldp(n), rdp(n), lptr(n), rptr(n), f1(f1), f2(f2), ident(ident) {}

    void add_edge(int u, int v, const Data &d) {
        g[u].emplace_back((Node){v, (int)g[v].size(), d});
        g[v].emplace_back((Node){u, (int)g[u].size() - 1, d});
    }

    void add_edge_bi(int u, int v, const Data &d, const Data &e) {
        g[u].emplace_back((Node){v, (int)g[v].size(), d});
        g[v].emplace_back((Node){u, (int)g[u].size() - 1, e});
    }

    T dfs(int idx, int par) {

        while (lptr[idx] != par && lptr[idx] < (int)g[idx].size()) {
            auto &e                 = g[idx][lptr[idx]];
            ldp[idx][lptr[idx] + 1] = f1(ldp[idx][lptr[idx]], f2(dfs(e.to, e.rev), e.data));
            ++lptr[idx];
        }
        while (rptr[idx] != par && rptr[idx] >= 0) {
            auto &e             = g[idx][rptr[idx]];
            rdp[idx][rptr[idx]] = f1(rdp[idx][rptr[idx] + 1], f2(dfs(e.to, e.rev), e.data));
            --rptr[idx];
        }
        if (par < 0)
            return rdp[idx][0];
        return f1(ldp[idx][par], rdp[idx][par + 1]);
    }

    vector<T> solve() {
        for (int i = 0; i < (int)g.size(); i++) {
            ldp[i].assign(g[i].size() + 1, ident);
            rdp[i].assign(g[i].size() + 1, ident);
            lptr[i] = 0;
            rptr[i] = (int)g[i].size() - 1;
        }
        vector<T> ret;
        for (int i = 0; i < (int)g.size(); i++) {
            ret.push_back(dfs(i, -1));
        }
        return ret;
    }
};

template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> id = {-inf, -inf, -inf};
    auto f1        = [](vector<int> a, vector<int> b) {
        vector<int> ret(3, -inf);
        for (auto &aa : a) {
            ret.push_back(aa);
        }
        for (auto &bb : b) {
            ret.push_back(bb);
        }
        sort(ret.begin(), ret.end(), greater<>());
        ret.resize(3);
        return ret;
    };
    auto f2 = [](vector<int> a, int d) { return vector<int>({max(0, a[0]) + d, -inf, -inf}); };
    ReRooting<int, vector<int>> g(n, f1, f2, id);
    for (int i = 0; i < n - 1; ++i) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        g.add_edge(s, t, 1);
    }
    pair<int, int> maxi = {0, 0};
    for (auto &p : g.solve()) {
        if (p[2] != -inf) {
            if (maxi.first < p[0] + min(p[1], p[2])) {
                maxi = {p[0] + min(p[1], p[2]), min(p[1], p[2])};
            } else if (maxi.first == p[0] + min(p[1], p[2])) {
                if (maxi.second > min(p[1], p[2]))
                    maxi = {p[0] + min(p[1], p[2]), min(p[1], p[2])};
            }
        }
    }
    if (maxi.second * 2 == maxi.first)
        maxi.first--;
    string ret(n, '1');
    for (int i = 2; i < n; ++i) {
        if (maxi.first >= i + 1)
            ret[i] = '0';
    }
    cout << ret << "\n";

    return 0;
}
