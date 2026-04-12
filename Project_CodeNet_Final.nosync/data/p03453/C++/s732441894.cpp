#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

#define LL long long
const int maxn = 100000 + 100;
const int maxm = 200000 + 100;
const LL MOD = 1000000000 + 7;
const LL INF = 1LL << 60;
struct Node {
    int pos;
    LL dis;
    Node() {}
    Node(int p, LL d) {
        pos = p;
        dis = d;
    }
};
bool operator<(const Node &a, const Node &b) {
    return a.dis > b.dis;
}
struct Edge {
    int u, v;
    LL dis;
};
int n, m, s, t, u, v;
LL d, min_dis, ans;
Edge edge[maxm];
priority_queue<Node> que;
vector<Node> G[maxn];
LL dp_t[maxn], dp_s[maxn];
LL dis_t[maxn], dis_s[maxn];

void bfs(int s, LL *dis, LL *dp) {
    memset(dis, 0x3f, sizeof(LL) * (n + 10));
    dis[s] = 0;
    dp[s] = 1;
    que.push(Node(s, 0));
    while(!que.empty()) {
        Node tmp = que.top();
        que.pop();
        int len = G[tmp.pos].size();
        for(int i = 0; i < len; ++i) {
            int pos = G[tmp.pos][i].pos;
            LL d = G[tmp.pos][i].dis;
            if(dis[pos] > tmp.dis + d) {
                dis[pos] = tmp.dis + d;
                dp[pos] = dp[tmp.pos];
                que.push(Node(pos, dis[pos]));
            } else if(dis[pos] == tmp.dis + d) {
                dp[pos] += dp[tmp.pos];
            }
            dp[pos] %= MOD;
        }
    }
}

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    ios::sync_with_stdio(false);

    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
        }
        scanf("%d%d", &s, &t);
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%lld", &u, &v, &d);
            edge[i].u = u;
            edge[i].v = v;
            edge[i].dis = d;
            G[u].push_back(Node(v, d));
            G[v].push_back(Node(u, d));
        }
        bfs(s, dis_s, dp_s);
        bfs(t, dis_t, dp_t);
        min_dis = dis_s[t];
        ans = (dp_s[t] * dp_s[t]) % MOD;
        for(int i = 1; i <= n; ++i) {
            if(dis_s[i] == dis_t[i] && dis_s[i] == min_dis / 2) {
                LL tmp = (dp_s[i] * dp_t[i]) % MOD;
                tmp = (tmp * tmp) % MOD;
                ans = (ans - tmp + MOD) % MOD;
            }
        }
        for(int i = 0; i < m; ++i) {
            int u = edge[i].u;
            int v = edge[i].v;
            if(dis_s[u] > dis_s[v]) {
                swap(u, v);
            }
            if(dis_s[u] + edge[i].dis + dis_t[v] == min_dis && dis_s[u] < min_dis / 2 && dis_s[v] > min_dis / 2) {
                LL tmp = (dp_s[u] * dp_t[v]) % MOD;
                tmp = (tmp * tmp) % MOD;
                ans = (ans - tmp + MOD) % MOD;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
