//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <set>
#include <stack>
#include <sstream>
#include <list>
//#include <array>
#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <iterator>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
typedef pair<int, int> pdi;
typedef pair<ll, int> pli;

int const maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
inline int lc(int x)  {return x << 1;}
inline int rc(int x)  {return x << 1 | 1;}

int n, m;
ll dis[2][maxn];
ll ans[2][maxn];
bool vis[2][maxn];
int const MOD = 1e9 + 7;
int st, ed;

struct Edge {
    int v, next, w;
}e[200000 << 1];
int head[maxn], cnt;

void init() {
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
    cnt = 0;
}

void add(int u, int v, int w) {
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void dijkstra(int s, ll d[], bool v[], ll ans[]) {
    priority_queue<pair<ll, int> > q;
    d[s] = 0;
    ans[s] = 1;
    q.emplace(0, s);
    while (!q.empty()) {
        int u = q.top().second;
        // cout << u << endl;
        q.pop();
        if (v[u]) continue;
        v[u] = 1;
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                ans[v] = ans[u];
                q.emplace(make_pair(-d[v], v));
            } else if (d[v] == d[u] + w) {
                ans[v] = (ans[v] + ans[u]) % MOD;
            }
        }
    }

}

int main(void) {
    FAST_IO;
    
    cin >> n >> m >> st >> ed;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dijkstra(st, dis[0], vis[0], ans[0]);
    dijkstra(ed, dis[1], vis[1], ans[1]);

    ll path = ((ans[0][ed] % MOD) * (ans[0][ed] % MOD)) % MOD;
    ll D = dis[0][ed];
    for (int i = 1; i <= n; i++) {
        if (dis[0][i] == dis[1][i] && D == dis[1][i] * 2) {
            path = path - ((ans[0][i] * ans[0][i] % MOD) * (ans[1][i] * ans[1][i] % MOD)) % MOD;
            path = (path + MOD) % MOD;
        }
        for (int u = head[i]; ~u; u = e[u].next) {
            int w = e[u].w;
            int v = e[u].v;
            ll d1 = dis[0][i], d2 = dis[1][v];
            if (d1 + w + d2 == D && d1 * 2 < D && d2 * 2 < D) {
                path = path - ((ans[0][i] * ans[0][i] % MOD) * (ans[1][v] * ans[1][v] % MOD)) % MOD;
                path = (path + MOD) % MOD;
            }
        }
    }
    cout << path << endl;
    
    return 0;
}