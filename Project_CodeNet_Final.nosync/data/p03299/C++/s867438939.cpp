#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

const long long MOD = 1000000007;

long long ModPow(long long x, long long n) {
        long long res = 1;
        while (n > 0) {
                if (n & 1) res = res * x % MOD;
                x = x * x % MOD;
                n >>= 1;
        }
        return res;
}

int main() {
        //input
        int n;
        scanf("%d", &n);
        vector<long long> h(n);
        for (int i = 0; i < n; i ++) {
                scanf("%lld", &h[i]);
        }
        // create a tree
        vector<vector<int>> g(n);
        map<int, pair<long long, int>> hw;
        int k = 0;
        function<void (int, int, long long, int)> dfs = [&](int l, int r, long long bottom, int prev) {
                int node = k ++;
                if (prev != -1) { 
                        g[prev].push_back(node);
                }
                long long mi = 10000000000;
                for (int i = l; i <= r; i ++) {
                        mi = min(mi, h[i]);
                }
                int ww = 0;
                int cnt = 0;
                for (int i = l; i <= r; i ++) {
                        ww += mi == h[i];
                        cnt ++;
                }
                long long hh = mi - bottom;
                hw[node] = make_pair(hh, ww);
                if (ww == cnt) {
                        return;
                }
                bool in = false;
                int tl, tr;
                vector<pair<int, int>> seg;
                for (int i = l; i <= r; i ++) {
                        if (h[i] > mi) {
                                if (!in) {
                                        in = true;
                                        tl = i;
                                }
                        } else {
                                if (in) {
                                        in = false;
                                        tr = i - 1;
                                        seg.emplace_back(tl, tr);
                                }
                        }
                }
                if (in) {
                        seg.emplace_back(tl, r);
                }
                for (auto s : seg) {
                        dfs(s.first, s.second, mi, node);
                }
        };
        dfs(0, n - 1, 0, -1);
        // solve
        vector<long long> dp(n), dp2(n);
        function<void (int)> solve = [&](int u) {
                long long mul1 = 1, mul2 = 1;
                for (auto v : g[u]) {
                        solve(v);
                        (mul1 *= dp[v]) %= MOD;
                        (mul2 *= (dp[v] + dp2[v])) %= MOD;
                }
                (dp[u] = ModPow(2LL, hw[u].first) * mul1) %= MOD;
                (dp2[u] = ModPow(2LL, hw[u].second) * mul2 % MOD + ((ModPow(2LL, hw[u].first) - 2) + MOD % MOD) * mul1 % MOD) %= MOD;
        };
        solve(0);
        //output
        printf("%lld\n", dp2[0]);
        return 0;
}

