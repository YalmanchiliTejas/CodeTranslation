#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n); i >= 0; i--)
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 2100100100;
const int MOD = 1e9 + 7;

int solve(int now, vector<int> pre_used, vector<vector<int>> &G) {
    vector<int> used = pre_used;
    used[now] = 1;
    bool end = true;
    REP(i, pre_used.size()) {
        if (used[i] != 1) {
            end = false;
            break;
        }
    }
    if (end) {
        return 1;
    }

    int ans = 0;
    for (auto v : G[now]) {
        if (used[v] != 1) {
            ans += solve(v, used, G);
        }
    }
    return ans;
}

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) == 1) {
        return 1;
    }

    vector<vector<int>> G(N); // adjacency list
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    vector<int> used(N, 0);
    printf("%d\n", solve(0, used, G));
    return 0;
}
