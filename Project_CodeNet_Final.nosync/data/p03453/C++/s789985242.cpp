#include <bits/stdc++.h>

using namespace std;


#ifdef zxc

#include <sys/resource.h>
#include "debug.h"
#include "profile.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define profile(X) LOG_DURATION(X)
#else
#define debug(...) 42
#define profile(...) 42
#endif

using ll = int64_t;
using ld = double;
const ld EPS = 1e-9;
const int MOD = 1e9 + 7;
const ld PI = 3.141592653589793;
const int maxn = 600001;
using cd = complex<double>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

set<int> g[maxn];
int bad[maxn];
vector<int> ng[maxn];
ll dp_up[maxn];
ll dp_down[maxn];

signed main() {
#ifdef zxc
    struct rlimit rl;
    const rlim_t kStackSize = 512L * 1024L * 1024L;
    assert(!getrlimit(RLIMIT_STACK, &rl));
    rl.rlim_cur = kStackSize;
    assert(!setrlimit(RLIMIT_STACK, &rl));
    freopen("../input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    //    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    //            freopen("", "r", stdin);
    //        freopen("hack.out", "w", stdout);
#endif
    profile("all");
    auto solve = [](int _) -> void {
        int n, m;
        cin >> n >> m;
        int s, t;
        cin >> s >> t;
        vector<tuple<int, int, int>> ed;
        for (int i = 1; i <= m; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            d *= 2;
            g[u].insert(ed.size());
            ed.emplace_back(u, v, d);
            g[v].insert(ed.size());
            ed.emplace_back(v, u, d);
        }
        vector<ll> d(n + 1);
        set<pair<ll, int>> q;
        fill(d.begin(), d.end(), 1e18);
        q.emplace(0, s);
        d[s] = 0;
        while (!q.empty()) {
            auto p = *q.begin();
            q.erase(q.begin());
            int v;
            ll dst;
            tie(dst, v) = p;
            for (int id:g[v]) {
                int to = get<1>(ed[id]);
                int to_add = get<2>(ed[id]);
                if (d[to] > d[v] + to_add) {
                    q.erase({d[to], to});
                    d[to] = d[v] + to_add;
                    q.insert({d[to], to});
                }
            }
        }
        int cnt = n;
        vector<tuple<int, int, int>> n_ed;
        ll X = d[t];
        debug(X);
        for (int id = 0; id < ed.size(); ++id) {
            int u, v, w;
            tie(u, v, w) = ed[id];
            if (d[v] != d[u] + w) {
                continue;
            }
            debug(u, v, w);
            if (d[v] <= X / 2 || d[u] >= X / 2) {
                ng[u].push_back(n_ed.size());
                n_ed.emplace_back(u, v, w);
            } else {
                ++cnt;
                ng[u].push_back(n_ed.size());
                n_ed.emplace_back(u, cnt, X / 2 - d[u]);
                ng[cnt].push_back(n_ed.size());
                n_ed.emplace_back(cnt, v, d[v] - X / 2);
            }
        }
        for (int i = 1; i <= n; ++i) {
            bad[i] = (d[i] == X / 2);
        }
        for (int i = n + 1; i <= cnt; ++i) {
            bad[i] = 1;
        }
        vector<int> order;
        vector<int> used(cnt + 1);
        function<void(int)> topsort = [&](int v) {
            used[v] = 1;
            for (int id:ng[v]) {
                int u = get<1>(n_ed[id]);
                if (!used[u]) {
                    topsort(u);
                }
            }
            order.push_back(v);
        };
        topsort(s);
        dp_down[t] = 1;
        for (int v:order) {
            for (int id:ng[v]) {
                int u = get<1>(n_ed[id]);
                dp_down[v] += dp_down[u];
                if (dp_down[v] >= MOD) {
                    dp_down[v] -= MOD;
                }
            }
        }
        reverse(order.begin(), order.end());
        dp_up[s] = 1;
        for (int v:order) {
            for (int id:ng[v]) {
                int u = get<1>(n_ed[id]);
                dp_up[u] += dp_up[v];
                if (dp_up[u] >= MOD) {
                    dp_up[u] -= MOD;
                }
            }
        }
        ll ans = 1ll * dp_down[s] * dp_down[s] % MOD;
        ans = ans % MOD;
        for (int i = 1; i <= cnt; ++i) {
            if (bad[i]) {
                ans = ans + MOD - dp_down[i] * dp_up[i] % MOD * dp_down[i] % MOD * dp_up[i] % MOD;
                ans %= MOD;
            }
        }
        for (int i = 1; i <= cnt; ++i) {
            debug(i, dp_up[i]);
            debug(i, dp_down[i]);
        }
        cout << ans;
    };


    fast_io();

    cout.precision(9);
    cout <<
         fixed;
    solve(1);

}
