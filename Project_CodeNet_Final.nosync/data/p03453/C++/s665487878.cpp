#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 82

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e5;
const ll INF = (1LL << 60);

vector < pair <int, int> > g[MAXN + 1];

struct Edge {
    int x, y;
    int d;
}edges[2 * MAXN + 1];

ll dst[2][MAXN + 1];
int dp[2][MAXN + 1];

priority_queue < pair <ll, int> > pq;

int n;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void dijkstra(int nod, bool t) {
    int i;
    for(i = 1; i <= n; i++) {
        dst[t][i] = INF;
    }
    dp[t][nod] = 1;
    dst[t][nod] = 0;
    pq.push({0, nod});
    while(!pq.empty()) {
        ll d = -pq.top().first;
        nod = pq.top().second;
        pq.pop();
        if(d != dst[t][nod])
            continue;
        for(auto it : g[nod]) {
            if(dst[t][it.first] > dst[t][nod] + it.second) {
                dst[t][it.first] = dst[t][nod] + it.second;
                dp[t][it.first] = dp[t][nod];
                pq.push({-dst[t][it.first], it.first});
            }
            else if(dst[t][it.first] == dst[t][nod] + it.second) {
                dp[t][it.first] += dp[t][nod];
                mod(dp[t][it.first]);
            }
        }
    }
}



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, m, s, t, x, y, d;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s >> t;
    for(i = 1; i <= m; i++) {
        cin >> x >> y >> d;
        g[x].push_back({y, d});
        g[y].push_back({x, d});
        edges[i] = {x, y, d};
    }
    dijkstra(s, 0);
    dijkstra(t, 1);
    int ans = (1LL * dp[0][t] * dp[0][t]) % MOD;
    for(i = 1; i <= n; i++) {
        if(dst[0][i] == dst[0][t] / 2 && dst[1][i] == dst[0][t] / 2) {
            int ways = (1LL * dp[0][i] * dp[1][i]) % MOD;
            ans = (ans - (1LL * ways * ways) % MOD);
            if(ans < 0)
                ans += MOD;
        }
    }
    for(i = 1; i <= m; i++) {
        x = edges[i].x;
        y = edges[i].y;
        d = edges[i].d;
        if(dst[0][x] > dst[0][y])
            swap(x, y);
        if(dst[0][x] + dst[1][y] + d == dst[0][t] && min(dst[0][x], dst[1][y]) + d > max(dst[0][x], dst[1][y])) {
            int ways = (1LL * dp[0][x] * dp[1][y]) % MOD;
            ans = (ans - (1LL * ways * ways) % MOD);
            if(ans < 0)
                ans += MOD;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
