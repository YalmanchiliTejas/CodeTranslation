#include <bits/stdc++.h>  // clang-format off
using namespace std;
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (int i = (a), lim_i = (b); i < lim_i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Fri Mar 20 16:17:15 JST 2020
 **/

template <class T> inline bool chmin(T& a, const T& b) {
    if (a <= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmax(T& a, const T& b) {
    if (a >= b) return false;
    a = b;
    return true;
}

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> depth(n);
    vector<vector<int>> ds(n, vector<int>(2, -1e9));
    auto dfs1 = [&](auto f, Int v, Int prv) -> void {
        for (Int s : g[v]) {
            if (s == prv) continue;
            f(f, s, v);
            ds[v].push_back(depth[s] + 1);
        }
        sort(ds[v].rbegin(), ds[v].rend());
        while (ds[v].size() > 2) ds[v].pop_back();
        depth[v] = max(0, ds[v][0]);
    };
    dfs1(dfs1, 0, -1);

    vector<int> mas(n + 1, -1);
    auto dfs2 = [&](auto f, Int v, Int prv) -> void {
        vector<int> cans(3, -1e9);
        if (prv != -1) {
            int tmp = (ds[prv][0] == depth[v] + 1 ? ds[prv][1] : ds[prv][0]) + 1;
            if (prv == 0) {
                tmp = max(1, tmp);
            } else {
                assert(tmp > 0);
            }
            cans.push_back(tmp);
            ds[v].push_back(tmp);
            sort(ds[v].rbegin(), ds[v].rend());
            ds[v].pop_back();
        }
        for (Int s : g[v]) {
            if (s == prv) continue;
            cans.push_back(depth[s] + 1);
            f(f, s, v);
        }
        sort(cans.rbegin(), cans.rend());
        if (cans[0] >= 0) chmax(mas[cans[0]], cans[0] + cans[2]);
    };
    dfs2(dfs2, 0, -1);

    for (int i = n - 1; i >= 0; i--) {
        mas[i] = max(mas[i], mas[i + 1]);
    }
    REP(k, 1, n + 1) {
        if (k == 1 || k == 2) {
            cout << 1;
        } else {
            cout << (mas[k / 2 + 1] >= k ? 0 : 1);
        }
    }
    cout << endl;
}

