#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Graph {
    int N;
    vector<vector<int>> edge;
    vector<vector<int>> dp;

public:
    Graph(int N) : N(N), edge(N) {}
    void add(int a, int b) {
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    int dfs(int i, int state) {
        if (dp[i][state]) return dp[i][state];
        if (state == (1 << N) - 1) {
            return dp[i][state] = 1;
        }
        for (auto &j : edge[i]) {
            if (!(state >> j & 1)) {
                dp[i][state] += dfs(j, state | (1 << j));
            }
        }
        return dp[i][state];
    }
    int ans() {
        dp = vector<vector<int>>(N, vector<int>(1 << N));
        return dfs(0, 1);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    Graph graph(N);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph.add(a, b);
    }
    cout << graph.ans() << endl;

    return 0;
}
